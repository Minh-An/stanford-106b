#include <cstdio>
#include <string>

using namespace std;

int evaluate(string exp, int& idx) {
    char ch = exp[idx]; 
    if(ch == '(') {
        int left = evaluate(exp, ++idx);
        char op = exp[++idx];
        int right = evaluate(exp, ++idx);
        idx++;
        if(op == '+') {
            return left + right;
        }
        else {
            return left * right;
        }
    }
    else {
        return ch - '0';
    }
}

int evaluate(string exp)
{
    int idx = 0;
    return evaluate(exp, idx);
}

int main()
{
    string exps[] = {"(2+2)", "((3*2)+5)", "((3+4)*((5+6)+3))"};
    for(string exp: exps)
    {
        printf("%s = %d\n", exp.c_str(), evaluate(exp));
    }
    return 0;
}