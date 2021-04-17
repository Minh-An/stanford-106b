#include <iostream>
#include <fstream>
#include <random>

using namespace std;

const int SIZE = 1000000;
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

    double *a = new double [SIZE];

    double avg = 0.;
    for(int i = 0; i < SIZE; i++)
    {
        uint64_t x = dist(gen);
        output.write((char*)(&x), NUM_BYTES);
        avg += x/SIZE;
    }

    output.write((char*)(&avg), NUM_BYTES);
    cout << avg << endl;

    output.close();
    return 0;
}