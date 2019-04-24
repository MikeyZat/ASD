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

void zad1() {
    bool A[N][N] = {{false, true, false, true,  true},
                    {true,  true, true,  false, false},
                    {false, true, false, true,  false},
                    {false, true, true,  false, false},
                    {false, true, true,  true,  true}};
    cout << possibleFields(A, 2, 3);
}


int main() {
    zad1();
}