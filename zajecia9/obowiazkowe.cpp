//
// Created by mikey on 24.04.2019.
//
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 5;

int possibleFields(bool A[N][N], int x, int y) {
    A[y][x] = false;
    int a, b, c, d;
    a = b = c = d = 0;
    if (x - 1 >= 0 && A[y][x - 1]) a = possibleFields(A, x - 1, y);
    if (x + 1 < N && A[y][x + 1]) b = possibleFields(A, x + 1, y);
    if (y - 1 >= 0 && A[y - 1][x]) c = possibleFields(A, x, y - 1);
    if (y + 1 < N && A[y + 1][x]) d = possibleFields(A, x, y + 1);
    return a + b + c + d + 1;
};

void tesdPI() {
    const int N = 3;
    bool tab[N][N];
    int results[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tab[i][j];
            results[i][j] = 0;
        }
    }

    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;
    if (tab[start_x][start_y]) {
        results[start_x][start_y] = 1;
    } else {
        cout << 0;
        return;
    }
    for (int i = start_x + 1; i < N; i++) {
        if (tab[start_y][i])
            results[start_y][i] = 1;
        else break;
    }
    for (int j = start_y + 1; j < N; j++) {
        if (tab[j][start_x])
            results[j][start_x] = 1;
        else break;
    }
    for (int i = start_x + 1; i < N; i++) {
        for (int j = start_y + 1; j < N; j++) {
            if(tab[i][j]){
                results[i][j]=results[i-1][j-1] + results[i-1][j] + results[i][j-1];
            }else{
                results[i][j]=0;
            }
        }
    }

    cout<<results[N-1][N-1];
}

void zad1() {
    bool A[N][N] = {{false, true, false, true,  true},
                    {true,  true, true,  false, false},
                    {false, true, false, true,  false},
                    {false, true, true,  false, false},
                    {false, true, true,  true,  true}};
    cout << possibleFields(A, 2, 3);
}


int main() {
//    zad1();
    tesdPI();
}