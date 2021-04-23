#include <cctype>
#include <cstdio>
#include <fstream>
#include <string> 
#include "vector.h"
#include "map.h"

using namespace std;

const int NUM_LETTERS = 26;

struct freqT 
{
    char letter;
    uint64_t freq;
};

void CreateFrequencies(string filename, Vector<freqT>& frequencies)
{
    ifstream input;
    input.open(filename);

    char c;
    while(!input.eof())
    {
        c = tolower(input.get());
        if(isalpha(c))
        {
            frequencies[c-'a'].freq++;
        }
    }
    input.close();
}

void WriteFrequencies(string filename, const Vector<freqT>& frequencies)
{
    ofstream output;
    output.open(filename, ofstream::binary);

    freqT* freq_arr = new freqT[NUM_LETTERS];
    for(int i = 0; i < frequencies.size(); i++)
    {
        freq_arr[i] = frequencies[i];
    }
    output.write((char*)(freq_arr), sizeof(freqT)*NUM_LETTERS);

    delete[] freq_arr;
    output.close();
}

void ReadFrequencies(string filename, Vector<freqT>& frequencies)
{
    ifstream input;
    input.open(filename, ifstream::binary);

    frequencies = Vector<freqT>(NUM_LETTERS);

    for(int i = 0; i < frequencies.size(); i++)
    {
        input.read((char*)(&frequencies[i]), sizeof(frequencies[i]));
    }

    input.close();
}

void CountLetters(string filename)
{
    Vector<freqT> frequencies(NUM_LETTERS);
    for(int i = 0; i < NUM_LETTERS; i++)
    {
        frequencies[i].letter = i + 'a';
        frequencies[i].freq = 0;
    }

    CreateFrequencies(filename, frequencies);
    WriteFrequencies("letters.bin", frequencies);
    Vector<freqT> file_frequencies;
    ReadFrequencies("letters.bin", file_frequencies);

    for(int i = 0; i < file_frequencies.size(); i++)
    {
        freqT letter_freq = file_frequencies[i];
        printf("%c: %llu\n", letter_freq.letter, letter_freq.freq);
    }
}

int main()
{
    CountLetters("letters.txt");
}