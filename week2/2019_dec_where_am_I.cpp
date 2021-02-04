#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int N;
string seq, substring;
set<string> elements;
bool flag = true;
int len = 0;

int main(void) {
    ifstream ifs ("whereami.in");
    ofstream ofs ("whereami.out");
    ifs >> N >> seq;

    while (flag) {
        flag = false;
        len++;
        // get substrings of length 1,2,...,N at each index
        for (int i=0; i<=N-len; i++) {
            substring = seq.substr(i, len);
            // if duplicates appear for a certain length, increment length and loop again
            if (elements.count(substring) != 0) {
                flag = true;
                break;
            }
            elements.insert(substring);
        }
    }

    ofs << len;
    return 0;
}