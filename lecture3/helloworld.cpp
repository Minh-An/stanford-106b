#include <iostream>
#include "simpio.h"

using namespace std;

double GetScoreAndAverage(int numScores);

int main()
{
    double average = GetScoreAndAverage(4);
    cout << "Average is " << average << endl;
    return 0;
}

double GetScoreAndAverage(int numScores)
{
    int sum; 
    for (int i = 0; i < numScores; i++)
    {
        cout << "Next? ";
        sum += getInteger();
    }
    return double(sum)/numScores;
    
}