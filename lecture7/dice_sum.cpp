#include <vector>
#include <cstdio>

using namespace std;

int calls = 0;

void DiceSum(int dice, int desiredSum, vector<int>& chosen)
{
    calls++;
    //printf("%d, %d\n", dice, desiredSum);
    if(dice == 0 && desiredSum == 0) {
        for(int c: chosen) printf("%d ", c);
        printf("\n");
    }
    else if (desiredSum >= dice && desiredSum <= dice * 6) {
        for(int i = 1; i <= 6; i++)
        {
            chosen.push_back(i);
            DiceSum(dice-1, desiredSum-i, chosen);
            chosen.pop_back();
        }
    }
}

void DiceSum(int dice, int desiredSum)
{
    vector<int> chosen;
    DiceSum(dice, desiredSum, chosen);
}

int main()
{
    DiceSum(3,7);
    printf("Calls: %d\n", calls);
}