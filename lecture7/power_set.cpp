#include <string> 
#include <vector>
#include <cstdio>

using namespace std;

void PowerSetHelper(vector<string>& v, vector<string>& chosen){
    if(v.empty()) {
        printf("{");
        for(string s: chosen) {
            printf("%s,", s.c_str());
        }
        printf("}\n");
    } else {
        string s = v[0];

        v.erase(v.begin());
        chosen.push_back(s);

        PowerSetHelper(v, chosen);

        chosen.pop_back();
        PowerSetHelper(v, chosen);

        v.insert(v.begin(), s);
    }
}

void PowerSet(vector<string>& v) {
    vector<string> chosen;
    PowerSetHelper(v, chosen);
}

int main() { 
    vector<vector<string> > tests{ 
        {"a","b","c"},
        {"1", "2", "3", "4"}
    };

    // expected for {a,b,c} is abc, acb, bac, bca, cab, cba
    // number of expected for {1,2,3,4} = 24
    for(vector<string> test: tests) {
        PowerSet(test);
    }
}