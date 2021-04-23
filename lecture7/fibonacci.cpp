#include <chrono>
#include <cstdio>
#include <iostream>
#include "stack.h"

using namespace std;

uint64_t RecursiveFibonacci(uint64_t n)
{
    if(n == 1 || n == 2) return 1;
    return RecursiveFibonacci(n-1) + RecursiveFibonacci(n-2);
}

uint64_t LoopFibonacci(uint64_t n)
{
    Stack<uint64_t> fibonacci;
    for(uint64_t i = 1; i <= n; i++)
    {
        if(i == 1 || i == 2) fibonacci.push(1);
        else
        {
            uint64_t prev = fibonacci.pop();
            uint64_t curr = fibonacci.pop() + prev;
            fibonacci.push(prev);
            fibonacci.push(curr);
        }
    }
    return fibonacci.peek();
}

uint64_t LoopFibonacci2(uint64_t n)
{
    if(n == 1 || n == 2) return 1;

    uint64_t fn; uint64_t fn_1 = 1; uint64_t fn_2 = 1;
    for(uint64_t i = 1; i < n-1; i++)
    {
        fn = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = fn;
    }
    return fn;
}

int main()
{
    printf("Testing fibonacci function....\n\n");

    printf("fibonacci using recursion of %d = %llu\n", 5, RecursiveFibonacci(5));
    printf("fibonacci using recursion of %d = %llu\n\n", 10, RecursiveFibonacci(10));

    printf("fibonacci using for loop of %d = %llu\n", 5, LoopFibonacci(5));
    printf("fibonacci using for loop of %d = %llu\n\n", 10, LoopFibonacci(10));

    printf("fibonacci using for loop v2 of %d = %llu\n", 5, LoopFibonacci2(5));
    printf("fibonacci using for loop v2 of %d = %llu\n\n", 10, LoopFibonacci2(10));

    printf("Enter n: ");
    int n;
    cin >> n;

    auto begin = chrono::steady_clock::now();
    uint64_t fibonacci = LoopFibonacci(n);
    auto end = chrono::steady_clock::now();
    auto time_diff = (chrono::duration_cast<chrono::milliseconds>(end - begin)).count();
    printf("loop stack fibonacci of %d = %llu took %llu ms\n", n, fibonacci, time_diff);

    begin = chrono::steady_clock::now();
    fibonacci = LoopFibonacci2(n);
    end = chrono::steady_clock::now();
    time_diff = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    printf("loop fibonacci of %d = %llu took %llu ms\n", n, fibonacci, time_diff);

    begin = chrono::steady_clock::now();
    fibonacci = RecursiveFibonacci(n);
    end = chrono::steady_clock::now();
    time_diff = std::chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    printf("recursive vfibonacci of 1000000 = %llu took %llu ms\n", fibonacci, time_diff);

}