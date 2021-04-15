#include <iostream>
#include <fstream> 
#include <string>
#include "error.h"
#include "strlib.h"
#include "stack.h"

using namespace std;


int main()
{
    Stack<string> lines;

    ifstream inFile;
    inFile.open("mydata.txt");

    string line;
    while(!inFile.fail())
    {
        getline(inFile, line);
        lines.push(toUpperCase(line));
    }
    inFile.close();


    ofstream outFile;
    outFile.open("mydata.copy");
    if(outFile.fail()) error("Couldn't open output file to copy");

    while(!lines.isEmpty())
    {
        outFile << lines.pop() << endl;
    }

    outFile.close();

    return 0;
}