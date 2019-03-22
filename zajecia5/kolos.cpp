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

void prepareSubstrings(int *substrings,int *t, int k, int n, int sub) {
    for (int i = k; i < n; i++) {
        substrings[sub] = 0;
        sub <<= 1;
        sub += t[i];
        sub &= 7;
    }
    substrings[sub] = 0;
}

int findMax(int *substrings,int *t, int k, int n, int sub){
    int max=substrings[sub];
    for (int i = k; i < n; i++) {
        substrings[sub]++;
        if(substrings[sub]>substrings[max])
            max=sub;
        sub <<= 1;
        sub += t[i];
        sub &= 7;
    }
    substrings[sub]++;
    if(substrings[sub]>substrings[max])
        max=sub;
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
    prepareSubstrings(substrings, tab,  k, n, sub);
    int max = findMax(substrings, tab,  k, n, sub);
    cout<<max;
    return " ";
}

void zad3Kolos2016() {
    string ciag = "ababaaaabb";
    string res = majorSubstring(ciag, 3);
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
}

int main() {

    zad3Kolos2016();
    return 0;
}
