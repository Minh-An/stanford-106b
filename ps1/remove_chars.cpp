#include <cstdio>
#include <string>

using namespace std;

string CensorString1(string text, string remove);
void CensorString2(string & text, string remove);

int main()
{
    string text1 = "Stanford University";
    string remove1 = "nt";

    string text2 = "Llamas like to laugh";
    string remove2 = "la";

    printf("Testing CensorString1:\n");
    printf("Stanford University and nt: %s\n", CensorString1(text1, remove1).c_str());
    printf("Llamas like to laugh and la: %s\n", CensorString1(text2, remove2).c_str());

    printf("--------------------------------------------\n");
    printf("Testing CensorString2:\n");
    string text1_cp1 = text1;
    string text2_cp1 = text2;
    CensorString2(text1_cp1, remove1);
    CensorString2(text2_cp1, remove2);
    printf("Stanford University and nt: %s\n", text1_cp1.c_str());
    printf("Llamas like to laugh and la: %s\n", text2_cp1.c_str());

    printf("--------------------------------------------\n");
    printf("Testing CensorString3:\n");
    string text1_cp2 = text1;
    string text2_cp2 = text2;
    CensorString2(text1_cp2, remove1);
    CensorString2(text2_cp2, remove2);
    printf("Stanford University and nt: %s\n", text1_cp2.c_str());
    printf("Llamas like to laugh and la: %s\n", text2_cp2.c_str());

}

string CensorString1(string text, string remove)
{
    string censored;
    for(int i = 0; i < text.length(); i++)
    {
        if(remove.find(text[i]) == string::npos)
            censored += text[i];
    }
    return censored;
}

void CensorString2(string & text, string remove)
{
    int i = 0;
    while(i < text.length())
    {
        if(remove.find(text[i]) != string::npos)
            text.erase(i, 1);
        else 
            i++;
    }
}

void CensorString3(string & text, string remove)
{
    int pos = 0;
    for(int i = 0; i < remove.length(); i++)
    {
        while((pos = text.find(remove[i], pos)) != string::npos)
        {
            text.erase(pos, 1);
        }
    }
}