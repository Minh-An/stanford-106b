#include <string> 
#include <vector>
#include <cstdio>

using namespace std;

void PermutationsHelper(vector<string>& v, vector<string>& chosen){
    if(v.empty()) {
        for(string s: chosen) {
            printf("%s ", s.c_str());
        }
        printf("\n");
    } else {
        for(int i = 0; i < v.size(); i++) {
            string s = v[i];

            v.erase(v.begin()+i);
            chosen.push_back(s);

            PermutationsHelper(v, chosen);

            v.insert(v.begin()+i, s);
            chosen.pop_back();
        }
    }
}

void Permutations(vector<string>& v) {
    vector<string> chosen;
    PermutationsHelper(v, chosen);
}

int main() { 
    vector<vector<string> > tests{ 
        {"a","b","c"},
        {"1", "2", "3", "4"}
    };

    // expected for {a,b,c} is abc, acb, bac, bca, cab, cba
    // number of expected for {1,2,3,4} = 24
    for(vector<string> test: tests) {
        Permutations(test);
    }
}