#include <cstdio>
#include "stack.h"

int RecursiveFactorial(int n)
{
    if(n == 1 || n == 0) return 1;
    return n * RecursiveFactorial(n-1);
}

int LoopFactorial(int n) 
{
    int factorial = 1;
    for(int i = 2; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int main()
{
    printf("Testing factorial function....\n\n");

    printf("factorial using recursion of %d = %d\n", 5, RecursiveFactorial(5));
    printf("factorial using recursion of %d = %d\n\n", 10, RecursiveFactorial(10));

    printf("factorial using for loop of %d = %d\n", 5, LoopFactorial(5));
    printf("factorial using for loop of %d = %d\n\n", 10, LoopFactorial(10));

}