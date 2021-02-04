#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> cows, cows1, cows2;
string cow1, cow2;
string words;
int N, index1, index2;

bool meet_constraints(void) {
    // check all N constraints one by one
    for (int i=0; i<N; i++) {
        // find the target cows' position
        for (int j=0; j<8; j++) {
            if (cows[j] == cows1[i]) {
                index1 = j;
            }
            if (cows[j] == cows2[i]) {
                index2 = j;
            }
        }
        // false if the distance's not equal to 1 (besides each other)
        if (abs(index1-index2) != 1) {
            return false;
        }
    }

    return true;
}

int main(void) {
    ifstream ifs ("lineup.in");
    ofstream ofs ("lineup.out");
    ifs >> N;

    // arrange the cows in alphabetical order
    cows.push_back("Beatrice");
    cows.push_back("Belinda");
    cows.push_back("Bella");
    cows.push_back("Bessie");
    cows.push_back("Betsy");
    cows.push_back("Blue");
    cows.push_back("Buttercup");
    cows.push_back("Sue");

    // get the input and fill in the corresponding array
    for (int i=0; i<N; i++) {
        ifs >> cow1;
        for (int j=0; j<4; j++) {
            ifs >> words;
        }
        ifs >> cow2;
        cows1.push_back(cow1);
        cows2.push_back(cow2);
    }

    // loop all possible permutation outcomes of the 8 cows
    do {
        // if the ordering meets all constraints, print it out and end the loop
        if (meet_constraints()) {
            for (int i=0; i<8; i++) {
                ofs << cows[i] << endl;
                cout << cows[i] << endl;
            }
            break;
        }
    } while (next_permutation(cows.begin(), cows.end()));

    return 0;
}