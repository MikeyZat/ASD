//
// Created by mikey on 22.03.2019.
//
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node {
    int val;
    node *next;
};

node *merge(node *first, node *second) {
    node *sorted = new node;
    node *tmp = sorted;
    while (first != nullptr && second != nullptr) {
        if (first->val <= second->val) {
            tmp->next = first;
            first = first->next;
            tmp->next->next = nullptr;
            tmp = tmp->next;
        } else {
            tmp->next = second;
            second = second->next;
            tmp->next->next = nullptr;
            tmp = tmp->next;
        }
    }
    if (first != nullptr) tmp->next = first;
    if (second != nullptr) tmp->next = second;
    tmp = sorted->next;
    delete sorted;
    return tmp;
}

int magicFives(int *t, int n, int k) {
    if (n < 7) {
        sort(t, t + n);
        return t[k];
    }

    int *medians = new int[n / 5 + 1];
    for (int i = 0; i < n; i += 5) {
        sort(t + i, t + i + min((n - i), 5));
        medians[i / 5] = t[i + min((n - i) / 2, 2)];
    }

    int m = magicFives(medians, n / 5 + 1, (n / 5 + 1) / 2);
    delete[] medians;

    int *lesser = new int[n];
    int *equal = new int[n];
    int *greater = new int[n];
    int greaterIndex = 0;
    int lesserIndex = 0;
    int equalIndex = 0;

    for (int i = 0; i < n; i++)
        if (t[i] < m)
            lesser[lesserIndex++] = t[i];
        else if (t[i] == m)
            equal[equalIndex++] = t[i];
        else
            greater[greaterIndex++] = t[i];

    if (lesserIndex > k) {
        int res = magicFives(lesser, lesserIndex, k);
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
    int res = magicFives(greater, greaterIndex, k - lesserIndex - equalIndex);

    delete[] lesser;
    delete[] equal;
    delete[] greater;
    return res;
}


int sumBetween(int *T, int from, int to, int n) {

    int lower = magicFives(T, n, from);
    int higher = magicFives(T, n, to);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (T[i] >= lower && T[i] <= higher)
            sum += T[i];
    }

    return sum;
}

void zad2Kolos2016() {
    int tab[10];
    for (int i = 0; i < 10; i++) {
        tab[i] = ((i + 3) * 17) % 33;
        cout << tab[i] << " ";
    }
    cout << endl;
    cout << sumBetween(tab, 3, 8, 10);
}

int digit(char letter) {
    return (int) (letter - 'a');
}

int initializeSub(int *t, int k) {
    int sub = 0;
    for (int i = 0; i < k; i++) {
        sub <<= 1;
        sub += t[i];
    }
    return sub;
}

void prepareSubstrings(int *substrings, int *t, int k, int n, int sub) {
    for (int i = k; i < n; i++) {
        substrings[sub] = 0;
        sub <<= 1;
        sub += t[i];
        sub &= 7;
    }
    substrings[sub] = 0;
}

int findMax(int *substrings, int *t, int k, int n, int sub) {
    int max = substrings[sub];
    for (int i = k; i < n; i++) {
        substrings[sub]++;
        if (substrings[sub] > substrings[max])
            max = sub;
        sub <<= 1;
        sub += t[i];
        sub &= 7;
    }
    substrings[sub]++;
    if (substrings[sub] > substrings[max])
        max = sub;
    return max;
}

string majorSubstring(string sentence, int k) {
    int n = sentence.size();
    int *substrings = new int[1 << k];
    int *tab = new int[n];
    for (int i = 0; i < n; i++) {
        tab[i] = digit(sentence[i]);
    }
    int sub = initializeSub(tab, k);
    prepareSubstrings(substrings, tab, k, n, sub);
    int max = findMax(substrings, tab, k, n, sub);
    cout << max;
    return " ";
}

void zad3Kolos2016() {
    string ciag = "ababaaaabb";
    string res = majorSubstring(ciag, 3);
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
}

struct help {
    int sum;
    int index;
};


int sumPartition(help t[], int left, int right) {
    int x = t[right].sum;

    int j = left;

    for (int i = left; i < right; i++) {
        if (t[i].sum < x) {
            help tmp = t[i];
            t[i] = t[j];
            t[j] = tmp;
            j++;
        }
    }
    help tmp = t[right];
    t[right] = t[j];
    t[j] = tmp;
    return j;
}


void quickSumSort(help t[], int left, int right) {
    if (left < right) {

        int q = sumPartition(t, left, right);

        quickSumSort(t, left, q - 1);
        quickSumSort(t, q + 1, right);
    }
}

void SumSort(int *A, int *B, int n) {
    help *sumTab = new help[n];
    for (int i = 0; i < n; i++) {
        sumTab[i].index = i;
        sumTab[i].sum = 0;
        for (int j = 0; j < n; j++) {
            sumTab[i].sum += A[i * n + j];
        }
    }

    quickSumSort(sumTab, 0, n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i * n + j] = A[sumTab[i].index * n + j];
        }
    }
    delete[] sumTab;

}


void zad1Kolos2015() {
    int A[16];
    for (int i = 0; i < 16; i++) {
        A[i] = ((i + 3) * 13) % 31;
        cout << A[i] << " ";
    }
    cout << endl;
    int B[16] = {0};
    SumSort(A, B, 4);

    for (int i = 0; i < 16; i++) {
        cout << B[i] << " ";
    }
}

int partition(int *t, int left, int right) {
    int x = t[right];
    int j = left ;
    for (int i = left; i < right; i++) {
        if (t[i] < x) {
            int tmp = t[i];
            t[i] = t[j];
            t[j] = tmp;
            j++;
        }
    }
    int tmp = t[right];
    t[right] = t[j];
    t[j] = tmp;
    return j;
}

void quicksort(int *t, int left, int right) {
    if (left < right) {

        int q = partition(t, left, right);
        quicksort(t, left, q - 1);
        quicksort(t, q + 1, right);
    }
}

void merge(int *A, int *B, int n, int k) {
    int *tmp = new int[n];
    int l = 0;
    int i = 0;
    int j = 0;
    while (i < n && j < k) {
        if (A[i] % 2 == 0) {
            i++;
        } else {

            if (A[i] < B[j])
                tmp[l++] = A[i++];
            else
                tmp[l++] = B[j++];
        }
    }
    while (i < n) {
        if (A[i] % 2 == 0) {
            i++;
        } else
            tmp[l++] = A[i++];
    }

    while (j < k)
        tmp[l++] = B[j++];

    for (int i = 0; i < n; i++) {
        A[i] = tmp[i];
    }

    delete[] tmp;
}

void sortEven(int *tab, int n) {
    int *even = new int[3];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (tab[i] % 2 == 0)
            even[j++] = tab[i];
    }

    cout << even[0] << " " << even[1] << " " << even[2] << endl;

    quicksort(even, 0, 2);

    cout << even[0] << " " << even[1] << " " << even[2] << endl;

    merge(tab, even, n, 3);

    delete[] even;
}


void zad2Kolos2015() {
    int A[8] = {1, 5, 4, 7, 11, 13, 2, 6};
    sortEven(A, 8);

    for (int i = 0; i < 8; i++) {
        cout << A[i] << " ";
    }
}

int digitFromChar(char a) {
    return (int) (a - 'a');
}

void countingSort(string A[], int start, int n, int pos) {
    string *results = new string[n];
    int *counters = new int[26];
    for (int i = 0; i < 26; i++)counters[i] = 0;
    for (int i = start; i < n; i++) {
        counters[digitFromChar(A[i][pos])]++;
    }
    for (int i = 1; i < 26; i++) {
        counters[i] += counters[i - 1];
    }

    for (int i = n - 1; i >= start; i--) {
        counters[digitFromChar(A[i][pos])]--;
        results[start + counters[digitFromChar(A[i][pos])]] = A[i];
    }

    for (int i = start; i < n; i++) A[i] = results[i];

    delete[] results;
    delete[] counters;
}

void sortStrings(string A[], int n) {
    int *sizes = new int[n];
    for (int i = 0; i < n; i++)
        sizes[i] = A[i].size();

    //quicksort(A,sizes,0,n-1);

    int max = sizes[n - 1] - 1;
    int start = n - 1;
    for (int i = max; i >= 0; i--) {
        while (sizes[start] - 1 >= i)
            start--;
        countingSort(A, start + 1, n, i);
    }
    delete[] sizes;
}

void zad1Kolos2014() {
    string A[8] = {"ac", "aca", "abc", "jds", "abcd", "jsad", "adsads", "ojdsoah"};
    sortStrings(A, 8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < A[i].size(); j++)
            cout << A[i][j];
        cout << endl;
    }
}

bool klusek(int *tab, int n, int k) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < tab[i]) max = tab[i];
    }
    int *values = new int[max];
    for (int i = 0; i < n; i++)
        values[tab[i]] = 0;

    int repeating = 0;
    int min = max;
    max = 0;
    for (int i = 0; i < k; i++) {           //tworzymy sobie naszą gąsięnicę o długości k
        if (values[tab[i]] > 0)      //tutaj sprawdzamy czy liczba już się powtórzyła
            repeating++;

        values[tab[i]]++;

        if (tab[i] > max) max = tab[i];             //potrzebne nam będą min i max w podciągiem
        if (tab[i] < min) min = tab[i];
    }

    for (int i = k; i < n; i++) {
        if ((max - min) == (k - 1) && repeating ==
                                      0)             //jeśli repeating==0 to znaczy że każda liczba w podciągu występuje dokładnie raz
            return true;

        if (values[tab[i - k]] > 1)
            repeating--;                 //jeśli if jest spełniony to znaczy że wcześniej liczby się powtarzały
        values[tab[i - k]]--;
        if (values[tab[i]] > 0)
            repeating++;                   //jeśli if jest spełniony to znaczy że po dodaniu tej liczby któreś liczby się powtarzają
        values[tab[i]]++;

        //tu jeszcze powinno być aktualizowanie minimum i maksimum ale do tego w sumie chyba potrzeba kopca
    }
    return ((max - min) == (k - 1) && repeating == 0);
}

bool possible(string u, string v, string w) {
    int *characters = new int[26];
    for (int i = 0; i < 26; i++) characters[i] = 0;

    int counter = 0;

    for (int i = 0; i < w.size(); i++) {
        if (characters[digitFromChar(w[i])] == 0)counter++;
        characters[digitFromChar(w[i])]++;
    }
    for (int i = 0; i < v.size(); i++) {
        characters[digitFromChar(v[i])]--;
        if (characters[digitFromChar(v[i])] == 0)counter--;
    }
    for (int i = 0; i < u.size(); i++) {
        characters[digitFromChar(u[i])]--;
        if (characters[digitFromChar(u[i])] == 0)counter--;
    }

    delete[] characters;
    return counter == 0;
}


int main() {
    int tab[10] = {32, 12, 412, 5, 5321, 4, 21, 4, 5, 13};
    quicksort(tab, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << tab[i] << " ";
    return 0;
}
