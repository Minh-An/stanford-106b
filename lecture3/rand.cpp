#include <cstdio>
#include "random.h"

using namespace std;


int main()
{
    int num = randomInteger(1, 10);
    printf("Number generated is %d\n", num);
    return 0;
}