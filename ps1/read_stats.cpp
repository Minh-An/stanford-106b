#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

struct statsT 
{
    uint8_t min;
    uint8_t max;
    float avg;
};

statsT ReadScoreStats(const string& filename);

int main()
{
    statsT score_stats = ReadScoreStats("scores.bin");
    printf("Score Statistics For The Class:\n");
    printf("Min Score: %d\n", score_stats.min);
    printf("Max Score: %d\n", score_stats.max);
    printf("Average Score: %.3f\n", score_stats.avg);
}

statsT ReadScoreStats(const string& filename)
{
    ifstream input;
    input.open(filename, ifstream::binary);

    int size;
    input.read((char *)(&size), sizeof(size));

    input.ignore(size);

    statsT score_stats;
    input.read((char*)(&score_stats), sizeof(statsT));
    return score_stats;
}