//
// Created by mikey on 11.03.2019.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


struct przedzial {
    int a;
    int b;
    bool worth;
};


void countingSort(int *tab, const int N, int basis) {

    int output[11];
    int count[11];
    for (int i = 0; i < N; i++) count[i] = 0;

    for (int i = 0; i < N; i++) count[(tab[i] / basis) % N]++;

    for (int i = 1; i < N; i++) count[i] += count[i - 1];

    for (int i = N - 1; i >= 0; i--) {
        count[(tab[i] / basis) % N]--;
        output[count[(tab[i] / basis) % N]] = tab[i];
    }

    for (int i = 0; i < N; i++) tab[i] = output[i];

}

void zadanie2() {
    int tab[11] = {54, 24, 89, 12, 42, 12, 1, 95, 14, 42, 0};
    countingSort(tab, 11, 1);
    countingSort(tab, 11, 11);
    for (int i = 0; i < 11; i++) {
        cout << tab[i] << " ";
    }
}

void quickSort(przedzial *tab, int lewy, int prawy) {
    if (prawy <= lewy) return;

    int i = lewy - 1, j = prawy + 1,
            pivot = tab[(lewy + prawy) / 2].a; //wybieramy punkt odniesienia

    while (true) {
        //szukam elementu wiekszego lub rownego piwot stojacego
        //po prawej stronie wartosci pivot
        while (pivot > tab[++i].a);

        //szukam elementu mniejszego lub rownego pivot stojacego
        //po lewej stronie wartosci pivot
        while (pivot < tab[--j].a);

        //jesli liczniki sie nie minely to zamień elementy ze soba
        //stojace po niewlasciwej stronie elementu pivot
        if (i <= j)
            //funkcja swap zamienia wartosciami tab[i] z tab[j]
            swap(tab[i], tab[j]);
        else
            break;
    }

    if (j > lewy)
        quickSort(tab, lewy, j);
    if (i < prawy)
        quickSort(tab, i, prawy);
}

int find_interval(przedzial *tab, const int N) {
    quickSort(tab,0,N-1);
    int max = 0;
    int max_index = -1;
    for (int i = 0; i < N; i++) {
        if (tab[i].worth) {
            int count = 0;
            for (int j = i + 1; j < N; j++) {
                if (tab[i].b >= tab[j].a) {
                    if (tab[i].b >= tab[j].b) {
                        tab[j].worth = false;
                        count++;
                    }
                } else
                    break;
            }
            if (count > max) {
                max = count;
                max_index = i;
            }
        }
    }
    return max_index;

}

void zadanie4() {
    //wartości początkowe do testów
    przedzial tab[6];
    tab[0].a = 4;
    tab[1].a = 1;
    tab[2].a = 3;
    tab[3].a = 6;
    tab[4].a = 4;
    tab[5].a = 8;
    tab[0].b = 7;
    tab[1].b = 5;
    tab[2].b = 11;
    tab[3].b = 9;
    tab[4].b = 9;
    tab[5].b = 15;
    tab[0].worth = true;
    tab[1].worth = true;
    tab[2].worth = true;
    tab[3].worth = true;
    tab[4].worth = true;
    tab[5].worth = true;
    int przedzial = find_interval(tab, 6);
    cout << tab[przedzial].a << " " << tab[przedzial].b;
}

int main() {
//    zadanie2();
//    zadanie4();
}
