#include <cstdio>
#include <string>

using namespace std;

void Binary(int digits, string output) {
    if(digits == 0) printf("%s\n", output.c_str());
    else {
        Binary(digits-1, output+'0');
        Binary(digits-1, output+'1');
    }
}

void Binary(int digits)
{
    Binary(digits, "");
}

int main()
{
    int n = 4;
    printf("%d digit binary numbers:\n", n);
    Binary(n);
    return 0;
}