//
// Created by mikey on 02.03.2019.
//
#include <iostream>
#include <vector>

using namespace std;

struct minMax {
    int min;
    int max;
};

struct twoNum {
    int num1;
    int num2;
};

minMax *findMinMax(int N, int t[]) {
    int max;
    int min;
    min = max = t[0];
    for (int i = 0; i < N - 1; i += 2) {
        if (t[i] < t[i + 1]) {
            if (t[i + 1] > max)
                max = t[i + 1];
            if (t[i] < min)
                min = t[i];
        } else {
            if (t[i] > max)
                max = t[i];
            if (t[i + 1] < min)
                min = t[i + 1];
        }
    }
    minMax *result = new minMax;
    result->max = max;
    result->min = min;
    return result;
}

bool findSum(int N, int t[], int sum, twoNum *&result) {
    int first = 0;
    int last = N - 1;
    while (first != last) {
        if (t[first] + t[last] < sum)
            first++;
        else if (t[first] + t[last] > sum)
            last--;
        else {
            result->num1 = t[first];
            result->num2 = t[last];
            return true;
        }
    }
    return false;
}

struct node {
    node *next;
    int value;
};

void printList(node *first) {
    while (first != nullptr) {
        cout << first->value << " ";
        first = first->next;
    }
    cout << endl;
}

node *createList() {
    node *first = new node;
    first->value = 45;
    first->next = nullptr;
    node *firstC = first;
    for (int i = 0; i < 10; i++) {
        node *newEl = new node;
        newEl->value = 100 - i * 2;
        newEl->next = nullptr;
        first->next = newEl;
        first = newEl;
    }
    return firstC;
}

node *revertList(node *first) {
    node *reverse = nullptr;
    while (first != nullptr) {
        node *tmp = reverse;
        reverse = first;
        first = first->next;
        reverse->next = tmp;
    }
    return reverse;
}


int main() {
}