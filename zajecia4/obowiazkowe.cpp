//
// Created by mikey on 15.03.2019.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct point {
    int a;
    int b;
};

point *sum(int *tab, int n, int x) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (tab[i] + tab[j] > x)j--;
        if (tab[i] + tab[j] < x)i++;
        if (tab[i] + tab[j] == x) {
            point *result = new point;
            result->a = i;
            result->b = j;
            return result;
        }
    }
    return nullptr;
}

void zadanie1() {
    int tab[10];
    for (int i = 0; i < 10; i++) {
        tab[i] = i + 1;
    }
    point *wynik = sum(tab, 10, 22);
    if (wynik != nullptr)
        cout << wynik->a << " " << wynik->b;
    cout << "nie ma";
}

int findMajority(int *tab, int n) {
    int counter = 0, majority;
    for (int i = 0; i < n; i++) {
        if (counter == 0)
            majority = i;
        if (tab[i] == tab[majority])
            counter++;
        else
            counter--;
    }
    counter = 0;
    for (int i = 0; i < n; i++){
        if(tab[i]==tab[majority])
            counter++;
    }
    if(counter>n/2)
        return majority;
    else
        return -1;
}


void zadanie3() {
    int tab[9];
    tab[0] = 2;
    tab[1] = 2;
    tab[2] = 2;
    tab[3] = 3;
    tab[4] = 2;
    tab[5] = 5;
    tab[6] = 2;
    tab[7] = 7;
    tab[8] = 1;
    int index = findMajority(tab, 9);
    if(index>=0)
        cout<<tab[index];
    else
        cout<<"nie ma";
}

int main() {
    zadanie3();

    return 0;
}

