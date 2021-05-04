#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "vector.h"

using namespace std;

const int MAX_DIGITS = 9;

void PopulateHistogram(ifstream& in, Vector<int>& histogram) {
    int score;
    while(true) {
        in >> score;
        if(in.eof()) break;
        histogram[score/10] += 1;
    }
}

int main() {
    Vector<int> hist(MAX_DIGITS+1, 0);

    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);
    ifstream in;
    in.open("res/"+filename);

    while(in.fail()) {
        cout << "Couldn't open file " << filename << ". Enter filename: ";
        getline(cin, filename);
        in.open("res/"+filename);
    }

    PopulateHistogram(in, hist);

    for(int i = 0; i <= MAX_DIGITS; i++) {
        string bar(hist[i], 'X');
        cout << i << "0-" << i << "9: " << bar << endl;
    }

    return 0;
}
