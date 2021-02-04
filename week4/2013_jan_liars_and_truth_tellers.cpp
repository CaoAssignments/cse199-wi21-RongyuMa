#include <iostream>
#include <fstream>
using namespace std;

int N, M;
int components[1005];

int main(void) {
    ifstream ifs ("truth.in");
    ofstream ofs ("truth.out");
    ifs >> N >> M;

    for (int i=0; i<N; i++) {
        components[i] = i + 1;
    }

    for (int number=0; number<M; number++) {
        int a, b;
        char c;
        ifs >> a >> b >> c;
        a--;
        b--;

        if (components[a] == components[b] || components[a] == -components[b]) {
            if ((components[a] == components[b]) ^ (c == 'T')) {
                ofs << number;
                return 0;
            }
        }
        else {
            int comp_f = (c == 'T' ? components[a] : -components[a]);
            int comp_s = components[b];
            for (int i=0; i<N; i++) {
                if (components[i] == comp_s) {
                    components[i] = comp_f;
                }
                else if (components[i] == -comp_s) {
                    components[i] = -comp_f;
                }
            }
        }
        
    }

    ofs << M;
    return 0;
}