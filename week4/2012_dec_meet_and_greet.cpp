#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int M, N, B, E;
int number, counter_a, counter_b, pre_b, pre_e;
char letter;
int arr_b[1000000];
int arr_e[1000000];
int b_pos = 0;
int e_pos = 0;
int answer = 0;

int main(void) {
    ifstream ifs ("greetings.in");
    ofstream ofs ("greetings.out");

    ifs >> M >> N;
    
    // load all steps that cow b has taken as +1 (right) or -1 (left) into a 1-d array
    counter_a = 0;
    for (int i=0; i<M; i++) {
        ifs >> number >> letter;
        for (int j=0; j<number; j++) {
            if (letter == 'L') {
                arr_b[counter_a+j] = -1;
            }
            if (letter == 'R') {
                arr_b[counter_a+j] = 1;
            }
        }
        counter_a += number;
    }

    // load all steps that cow e has taken as +1 (right) or -1 (left) into a 1-d array
    counter_b = 0;
    for (int i=0; i<N; i++) {
        ifs >> number >> letter;
        for (int j=0; j<number; j++) {
            if (letter == 'L') {
                arr_e[counter_b+j] = -1;
            }
            if (letter == 'R') {
                arr_e[counter_b+j] = 1;
            }
        }
        counter_b += number;
    }

    // check if cow b and cow e are at the same position for each unit of time
    for (int k=0; k<max(counter_a, counter_b); k++) {
        pre_b = b_pos;
        if (k < counter_a) {
            b_pos += arr_b[k];
        }
        else {
            b_pos += 0;
        }

        pre_e = e_pos;
        if (k < counter_b) {
            e_pos += arr_e[k];
        }
        else {
            e_pos += 0;
        }

        // only increment when they left each other and met again (not walking along with each other)
        if (pre_b != pre_e && b_pos == e_pos) {
            answer += 1;

        }
    }
    
    ofs << answer;
    return 0;
}
