#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

const int MAX_SCORE = 100;
const int MIN_SCORE = 0;

struct statsT 
{
    uint8_t min;
    uint8_t max;
    float avg;
};

statsT ComputeScoreStats(const string& filename);

int main()
{
    statsT score_stats = ComputeScoreStats("scores.txt");
    printf("Score Statistics For The Class:\n");
    printf("Min Score: %d\n", score_stats.min);
    printf("Max Score: %d\n", score_stats.max);
    printf("Average Score: %.3f\n", score_stats.avg);
}

statsT ComputeScoreStats(const string& filename)
{
    statsT score_stats;
    score_stats.min = MAX_SCORE;
    score_stats.max = MIN_SCORE;
    score_stats.avg = 0;

    ifstream input;
    input.open(filename, ifstream::binary);

    string scores;
    int x; 
    int size = 0;
    while(!input.eof())
    {
        input >> x;
        if(x < score_stats.min) score_stats.min = x;
        if(x > score_stats.max) score_stats.max = x;
        score_stats.avg += x;
        scores += uint8_t(x);
        size++;
    }

    ofstream output;
    output.open("scores.bin", ofstream::binary);

    output.write((char*)(&size), sizeof(size));
    output.write(scores.c_str(), size);

    score_stats.avg /= size;
    output.write((char*)(&score_stats), sizeof(score_stats));
    return score_stats;
}