#include <cstdio>
#include <fstream>
#include <string> 
#include <unordered_map>
#include "tokenscanner.h"
#include "strlib.h"

using namespace std;

const string IGNORE_WORDS[] = {"the", "and", "you", "that", "not"};
const int MIN_WORD_LENGTH = 3;

void CountOccurences(string filename, unordered_map<string, int>& occurences)
{
    ifstream input; 
    input.open(filename);
    if(input.fail()) printf("Failed to open %s file.\n", filename.c_str());

    TokenScanner scanner(input);
    scanner.ignoreWhitespace();
    string word;
    while(scanner.hasMoreTokens())
    {
        word = toLowerCase(scanner.nextToken());
        if(word.length() >= MIN_WORD_LENGTH) occurences[word] += 1;
    }

    input.close();
}

int main()
{
    unordered_map<string, int> word_occurences; 
    CountOccurences("test.txt", word_occurences);

    string max_word;
    int max_occurrences = 0; 

    unordered_map<string, int>::iterator it;
    bool ignore = false;
    for(it = word_occurences.begin(); it != word_occurences.end(); it++)
    {
        ignore = false;
        for(string word: IGNORE_WORDS)
        {
            if(it->first == word) 
            {
                ignore = true;
                break;
            }
        }
        if(!ignore && it->second > max_occurrences) 
        {
            max_word = it->first;
            max_occurrences = it->second;
        }
    }
    printf("Max word %s: %d\n", max_word.c_str(), max_occurrences);
}