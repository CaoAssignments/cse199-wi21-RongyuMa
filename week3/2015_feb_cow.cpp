#include <iostream>
#include <fstream>
using namespace std;

int N;
long long num_c, num_co, num_cow; // the answer could be very big
string sequence;

int main(void) {
    ifstream ifs ("cow.in");
    ofstream ofs ("cow.out");

    ifs >> N >> sequence;
    num_c = num_co = num_cow = 0;

    // loop through the input sequence
    for (int i=0; i<N; i++) {
        // get all COW combinations
        if (sequence[i] == 'W') {
            num_cow = num_cow + num_co;
        }
        // get all CO combinations
        if (sequence[i] == 'O') {
            num_co = num_co + num_c;
        }
        // get the number of Cs
        if (sequence[i] == 'C') {
            num_c++;
        }
    }

    ofs << num_cow;

    return 0;
}
