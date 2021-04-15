#include <fstream> 
#include <string>
#include "error.h"
#include "strlib.h"

using namespace std;


int main()
{
    ifstream in;
    in.open("mydata.txt");
    if(in.fail()) error("Couldn't open input file");

    ofstream out;
    out.open("mydata.copy");
    if(out.fail()) error("Couldn't open output file to copy");

    string line;
    while(!in.fail())
    {
        getline(in, line);
        out << toUpperCase(line) << endl;
    }
    in.close();
    out.close();

    return 0;
}