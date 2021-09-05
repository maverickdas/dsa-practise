#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> & board) {
    int N = 9;
    unordered_set<char> rowSet[N];
    unordered_set<char> colSet[N];
    unordered_set<char> sqSet[N];

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char v = board[i][j];
            if (v == '.') continue;
            int sqPos = (i / 3) * 3 + j / 3;

        }
    }
}