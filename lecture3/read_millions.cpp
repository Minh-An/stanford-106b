#include <iostream>
#include <fstream>
#include <random>
#include "vector.h"

using namespace std;

const int NUM_ENTRIES = 1000000;
const int NUM_BYTES = 8;

int main()
{
    ifstream input;
    input.open("nums.data", ifstream::binary);

    if(input.fail()) error("Couldn't open nums.data for writing.");

    uint64_t num;
    double avg = 0.;
    for(int i = 0; i < NUM_ENTRIES; i++)
    {
        input.read((char *)(&num), NUM_BYTES);
        avg += num/NUM_ENTRIES;
    }

    double file_avg;
    input.read((char *)(&file_avg), NUM_BYTES);
    cout << "Calculated average: " << (avg) << "; File average: " << file_avg << endl;

    input.close();
    return 0;
}