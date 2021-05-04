#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include "console.h"
#include "strlib.h"

using namespace std;

const int SOUNDEX_DIGITS = 7;
const int MAX_SOUNDEX_LENGTH = 4;

void PopulateDictionary(const string& filename, unordered_map<char, int>& dict) {
    ifstream in;
    in.open(filename);
    string line;
    for(int i = 0; i < SOUNDEX_DIGITS; i++) {
        getline(in, line);
        int pos;
        while((pos = line.find(' ')) != string::npos) {
            dict.emplace(line[0], i);
            line = line.substr(pos+1);
        }
        dict.emplace(line[0], i);
    }
}

string Soundex(const string& name, unordered_map<char, int>& dict)
{
    string code(1, name[0]);
    int prev = -1;
    for(int i = 1; i < name.size(); i++)
    {
        int letter_code = dict[toupper(name[i])];
        if(letter_code != 0 && letter_code != prev) code += integerToString(letter_code);
        prev = letter_code;
    }
    code = code.substr(0, MAX_SOUNDEX_LENGTH);
    while(code.size() < MAX_SOUNDEX_LENGTH) code += "0";
    return code;
}

int main3() {
    unordered_map<char, int> dict;
    PopulateDictionary("res/soundex.txt", dict);

    string name;
    while(true) {
        cout << "Enter surname (RETURN to quit): ";
        getline(cin, name);
        if (name.empty()) return 0;
        string code = Soundex(name, dict);
        cout << "Soundex code for " << name << " is " << code << endl;
    }
    return 0;
}
