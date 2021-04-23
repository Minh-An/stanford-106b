#include <string>
#include <iostream>

using namespace std;

bool IsPalindrome(const string& word)
{
    int n = word.length();
    if(n <= 1) return true;
    return (tolower(word[0]) == tolower(word[n-1])) && IsPalindrome(word.substr(1, n-2));
}

int main()
{
    string word;
    printf("Enter word: ");
    cin >> word;
    if(IsPalindrome(word)) printf("%s is a palindrome.\n", word.c_str());
    else printf("%s is NOT a palindrome.\n", word.c_str());
}