#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string S, T, C;
int counter, T_len;

int main(void) {
    ifstream ifs ("censor.in");
    ofstream ofs ("censor.out");

    ifs >> S >> T; 
    T_len = T.length();
    counter = 0;

    // put the characters into a new string one by one
    for (int i=0; i<S.length(); i++) {
        C += S[i];
        counter++;

        // as soon as T is found, delete it and resize the string
        if (((counter - T_len) >= 0) && (C.substr(counter - T_len) == T)) {
            C.resize(counter - T_len);
            counter = counter - T_len;
        }
    }

    ofs << C;

    return 0;
}