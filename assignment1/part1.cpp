#include <cstdio>

using namespace std;

bool IsPerfect(int n)
{
    int sum = 0;
    for(int i = 1; i <= n/2; i++)
    {
        if(n%i == 0) sum += i;
    }
    return n == sum;
}

int main()
{
    for(int i = 1; i <= 10000; i++)
    {
        if(IsPerfect(i)) printf("%d is a perfect number.\n", i);
    }
}