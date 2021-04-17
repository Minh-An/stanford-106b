#include <iostream>
#include <fstream>
#include <random>

using namespace std;

const int NUM_ENTRIES = 1000000;
const int NUM_BYTES = 8;
const uint64_t LOW = 5000000000;
const uint64_t HIGH = 6000000000;

int main()
{
    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<uint64_t> dist(LOW, HIGH);

    ofstream output;
    output.open("nums.data", ofstream::binary);

    uint64_t* a = new uint64_t [NUM_ENTRIES];

    double avg = 0.;
    for(int i = 0; i < NUM_ENTRIES; i++)
    {
        uint64_t x = dist(gen);
        a[i] = x;
        avg += x;
    }
    avg /= NUM_ENTRIES;

    output.write((char*)(a), NUM_BYTES*NUM_ENTRIES);
    output.write((char*)(&avg), NUM_BYTES);
    cout << avg << endl;

    delete[] a;
    output.close();
    return 0;
}