//
// Created by mikey on 15.03.2019.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

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

int magicznePiatki(int *tab, int n, int k) {
    if (n <= 7) {
        sort(tab, tab + n);
        return tab[k];
    }

    int *medians = new int[n / 5 + 1];
    for (int i = 0; i < n; i += 5) {
        sort(tab + i, tab + i + min(5, n - i));
        medians[i / 5] = tab[i + min(2, (n - i) / 2)];
    }
    int m = magicznePiatki(medians, n / 5 + 1, (n / 5 + 1) / 2);
    delete[] medians;

    int *lesser = new int[n];
    int *equal = new int[n];
    int *greater = new int[n];
    int greaterIndex = 0;
    int lesserIndex = 0;
    int equalIndex = 0;

    for (int i = 0; i < n; i++)
        if (tab[i] < m)
            lesser[lesserIndex++] = tab[i];
        else if (tab[i] == m)
            equal[equalIndex++] = tab[i];
        else
            greater[greaterIndex++] = tab[i];

    if (lesserIndex > k) {
        int res = magicznePiatki(lesser, lesserIndex, k);
        delete[] greater;
        delete[] equal;
        delete[] lesser;

        return res;
    } else if (lesserIndex + equalIndex > k) {
        delete[] lesser;
        delete[] equal;
        delete[] greater;

        return m;
    }
    int res = magicznePiatki(greater, greaterIndex, k - lesserIndex - equalIndex);

    delete[] lesser;
    delete[] equal;
    delete[] greater;
    return res;
}


int findMedian(int *tab, int N) {
    return magicznePiatki(tab, N, N / 2);
}

void zadanie2() {
    int tab[10];
    for (int i = 0; i < 10; i++) {
        tab[i] = ((i + 1) * 7) % 17;
        cout << tab[i] << " ";
    }
    cout << endl;

    int median = findMedian(tab, 10);
    cout << median;
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
    for (int i = 0; i < n; i++) {
        if (tab[i] == tab[majority])
            counter++;
    }
    if (counter > n / 2)
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
    if (index >= 0)
        cout << tab[index];
    else
        cout << "nie ma";
}

struct Pupil {
    int group;
    Pupil *next;
};

int distaceToIdeal(Pupil *first) {
    Pupil *fast = first->next;
    Pupil *slow = first;
    int n = 1;
    while (fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        n++;
    }
    int i = 1, j = n + 1, sum = 0;
    slow = slow->next;
    while (i < n + 1 && j < 2 * n + 1) {
        while (i < n + 1 && first->group == 0) {
            first = first->next;
            i++;
        }
        while (j < 2 * n + 1 && slow->group == 1) {
            slow = slow->next;
            j++;
        }
        if (i < n + 1 && j < 2 * n + 1) {
            sum += j - i;
            i++;
            j++;
            first = first->next;
            slow = slow->next;
        }
    }
    return 2 * sum;
}

struct element {
    int value;
    int start;
    int index;


};

void heapifyMax(element t[], int i, int SIZE) {       //heapify z wykładu (naprawianie kopca)
    int left = i * 2;                   //kto nie uważał na wykłądzie (jak ja) polecam stronkę
    int right = i * 2 + 1;              // http://informatyka.wroc.pl/node/433?page=0,2
    int largest;
    if (left < SIZE + 1 && t[left].value > t[i].value)
        largest = left;
    else
        largest = i;
    if (right < SIZE + 1 && t[right].value > t[largest].value)
        largest = right;
    if (largest != i) {
        element pom = t[i];
        t[i] = t[largest];
        t[largest] = pom;
        heapifyMax(t, largest, SIZE);
    }
}
void buildMax(element t[], int SIZE) {        //budowanie kopca max
    for (int i = SIZE / 2; i >= 1; i--) {
        heapifyMax(t, i, SIZE);
    }
}


void sortNNsequence(int A[], int n) {
    element* kopiec = new element[n+1];
    int size = n;
    for (int i = n - 1; i < n * n; i += n) {
        kopiec[(i / n) + 1].value = A[i];
        kopiec[(i / n) + 1].start = i - n + 1;
        kopiec[(i / n) + 1].index = n - 1;
    }
    int *tab = new int[n * n];
    int i = 0;
    buildMax(kopiec, size);
    while (size > 0) {
        tab[i] = kopiec[1].value;
        i++;
        int index = kopiec[1].index;
        int start = kopiec[1].start;
        if (index > 0) {
            kopiec[1].value = A[start + index - 1];
            kopiec[1].index--;
        } else {
            kopiec[1] = kopiec[size];
            size--;
        }
        heapifyMax(kopiec, 1, size);
    }
    for (i = 0; i < n * n; i++) {
        A[i] = tab[i];
    }
    delete[] kopiec;
    delete[] tab;
}




int main() {

    return 0;
}

