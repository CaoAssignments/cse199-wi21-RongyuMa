#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

int N;    

void dfs_top_left(char** matrix, int x, int y, unordered_set<string>* sets, string curr) {
    if (x + y == N - 1) {
        sets[x].insert(curr + matrix[x][y]);
    }
    else {
        dfs_top_left(matrix, x+1, y, sets, curr + matrix[x][y]);
        dfs_top_left(matrix, x, y+1, sets, curr + matrix[x][y]);
    }
}

void dfs_bot_right(char** matrix, int x, int y, unordered_set<string>* sets, string curr) {
    if (x + y == N - 1) {
        sets[x].insert(curr + matrix[x][y]);
    }
    else {
        dfs_bot_right(matrix, x-1, y, sets, curr + matrix[x][y]);
        dfs_bot_right(matrix, x, y-1, sets, curr + matrix[x][y]);
    }
}

int main(void) {
    ifstream ifs ("palpath.in");
    ofstream ofs ("palpath.out");
    ifs >> N;
	char** matrix = new char*[N];

    for (int i=0; i<N; i++) {
		matrix[i] = new char[N];
        for (int j=0; j<N; j++) {
            ifs >> matrix[i][j];
        }
    }
    unordered_set<string>* top_left = new unordered_set<string>[N];
    unordered_set<string>* bot_right = new unordered_set<string>[N];
	
    dfs_top_left(matrix, 0, 0, top_left, "");
    dfs_bot_right(matrix, N-1, N-1, bot_right, "");

    unordered_set<string> answer;
    for (int a=0; a<N; a++) {
        for (string s: top_left[a]) {
            if (bot_right[a].find(s) != bot_right[a].end()) {
                answer.insert(s);
            }
        }
    }
	ofs << answer.size();
    for (int i = 0; i< N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] top_left;
    delete[] bot_right;

    return 0;
}