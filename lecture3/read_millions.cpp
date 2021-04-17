#include <iostream>
#include <fstream>
#include <random>
#include "vector.h"

using namespace std;

const int SIZE = 1000000;
const int NUM_BYTES = 8;

int main()
{
    ifstream input;
    input.open("nums.data", ifstream::binary);

    if(input.fail()) error("Couldn't open nums.data for writing.");

    uint64_t num;
    double avg = 0.;
    for(int i = 0; i < SIZE; i++)
    {
        input.read((char *)(&num), NUM_BYTES);
        avg += num/SIZE;
    }

    double file_avg;
    input.read((char *)(&file_avg), NUM_BYTES);
    cout << "Calculated average: " << (avg) << "; File average: " << file_avg << endl;

    input.close();
    return 0;
}