#include <iostream>
#include <fstream>
using namespace std;

#define NMAX 50000

int N;
string cows[NMAX];
string min_arr[NMAX];
string max_arr[NMAX];
string s_min[NMAX];
string s_max[NMAX];

int main(void) {
    ifstream ifs ("scramble.in");
    ofstream ofs ("scramble.out");

    ifs >> N;
    for (int i=0; i<N; i++) {
        ifs >> cows[i];

        // sort each string alphabetically
        sort(cows[i].begin(), cows[i].end());
        //s_min is the array of alphabetically sorted strings
        s_min[i] = cows[i];
        min_arr[i] = cows[i];

        // sort each string in reverse alphabetical order
        reverse(cows[i].begin(), cows[i].end());
        //s_max is the array of reverse alphabetically sorted strings
        s_max[i] = cows[i];
        max_arr[i] = cows[i];
    }

    // min_arr is the alphabetically sorted array
    sort(min_arr, min_arr + N);
    // max_arr is the reverse alphabetically sorted array
    sort(max_arr, max_arr + N);

    
    for (int m=0; m<N; m++) {
        // loop through max_arr and find a string's lowest possible position
        for (int n=0; n<N; n++) {
            if (max_arr[n].compare(s_min[m]) >= 0) {
                ofs << n+1 << ' ';
                break;
            }
            if (n == N-1) {
                ofs << N << ' ';
            }
        }

        // loop through min_arr and find a string's highest possible position
        for (int k=0; k<N; k++) {
            if (min_arr[k].compare(s_max[m]) > 0) {
                ofs << k << endl;
                break;
            }
            if (min_arr[k].compare(s_max[m]) == 0) {
                ofs << k+1 << endl;
                break;
            }
            if (k == N-1) {
                ofs << N << endl;
            }
        }
    }

    return 0;
}