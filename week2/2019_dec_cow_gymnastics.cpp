#include <iostream>
#include <fstream>
using namespace std;

int K, N;
int data [10][20];
int val_f, val_s;

int main(void) {
    ifstream ifs ("gymnastics.in");
    ofstream ofs ("gymnastics.out");

    ifs >> K >> N;
    
    // store data in a 2D array for easy access
    for (int a=0; a<K; a++) {
        for (int b=0; b<N; b++) {
            ifs >> data[a][b];
        }
    }

    int result = 0;
    // loop through all possible pairs given N numbers
    for (int a=1; a<=N; a++) {
        for (int b=1; b<=N; b++) {
            int counter = 0;
            // check all K rows
            for (int row=0; row<K; row++) {
                // check if val_f < val_s
                for (int col=0; col<N; col++) {
                    if (data[row][col] == a) {
                        val_f = col;
                    }
                    if (data[row][col] == b) {
                        val_s = col;
                    }
                }
                if (val_f < val_s) {
                    counter += 1;
                }
            }
            // increment result when val_f < val_s holds for all K rows
            if (counter == K) {
                result ++;
            }
        }
    }

    ofs << result << endl;
    return 0;
}