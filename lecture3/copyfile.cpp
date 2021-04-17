#include <fstream> 
#include <string>
#include "error.h"
#include "strlib.h"

using namespace std;


int main()
{
    ifstream in;
    in.open("mydata.txt");
    ofstream out;
    out.open("mydata.copy");

    if(in.fail() || out.fail()) error("Couldn't open files");

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