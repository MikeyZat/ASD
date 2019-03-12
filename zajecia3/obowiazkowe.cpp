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

void quickSort(przedzial *tab, int left, int right) {
    if (right <= left) return;

    int i = left - 1, j = right + 1,
            pivot = tab[(left + right) / 2].a; //wybieramy punkt odniesienia

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

    if (j > left)
        quickSort(tab, left, j);
    if (i < right)
        quickSort(tab, i, right);
}

int find_interval(przedzial *tab, const int N) {
    quickSort(tab, 0, N - 1);
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
    int interval = find_interval(tab, 6);
    cout << tab[interval].a << " " << tab[interval].b;
}

struct point {
    int x;
    int y;
};

struct container {
    point a;
    point b;
};

int howManyContainers(container *tab, const int n, int a) {
    int max = tab[0].a.y;
    int min = tab[0].b.y;
    for (int i = 1; i < n; i++) {
        if (tab[i].a.y > max)max = tab[i].a.y;
        if (tab[i].b.y < min)min = tab[i].b.y;                  //finding min level and max level
    }
    int hash = min;
    int size = max - hash + 1;                                  //translating levels to indexes
    int *water = new int[size];
    int *filled_containers = new int[size];
    for (int i = 0; i < size; i++)filled_containers[i] = water[i] = 0;

    for (int i = 0; i < n; i++) {
        water[tab[i].b.y - hash] += tab[i].b.x - tab[i].a.x;            //adding a width of container to each level
        water[tab[i].a.y - hash] += tab[i].a.x - tab[i].b.x;
        filled_containers[tab[i].a.y - hash - 1] += 1; // I dont really know why -1 in index but it works XD
    }
    for (int i = 1; i < size; i++)
        water[i] += water[i - 1];             //prefix sum (after that 'water'
    // of each index contains right amount of water on each level

    for (int i = 1; i < size; i++) {
        water[i] += water[i - 1];   //after this each index contains an amount of water 'under' that level
        filled_containers[i] += filled_containers[i - 1];  //answers our exercise question
    }

    int i = 1;
    while (i < size && a >= water[i])   //should have used binary search here
        i++;

    int result = filled_containers[i - 1];
    delete[] water;              //cleaning memory
    delete[] filled_containers;
    return result;
};

void zadanie3() {
    int n;
    cout << "podaj n" << endl;
    cin >> n;
    container tab[10];
    cout << "podaj współrzędne zbiorników" << endl;
    for (int i = 0; i < n; i++) {
        cin >> tab[i].a.x >> tab[i].a.y >> tab[i].b.x >> tab[i].b.y;
    }
    int a;
    cout << "podaj a" << endl;
    cin >> a;
    cout << howManyContainers(tab, n, a);
}

int main() {
//    zadanie2();
    zadanie3();
//    zadanie4();
}
