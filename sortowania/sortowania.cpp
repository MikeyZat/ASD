#include<iostream>

using namespace std;
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

void insert(node *&sorted, node *notSorted) {           //przez referencję bo może się zmienić początek listy
    if (sorted->value > notSorted->value) {             //wstawianie na początek listy
        notSorted->next = sorted;
        sorted = notSorted;
        return;
    }
    node *sortedCopy = sorted;
    while (sortedCopy->next != nullptr &&
           sortedCopy->next->value < notSorted->value) {             //szukamy miejsca w które wstawić
        sortedCopy = sortedCopy->next;
    }
    notSorted->next = sortedCopy->next;
    sortedCopy->next = notSorted;                                   //wstawianko
}

node *insertionSort(node *first) {
    if (first == nullptr) return nullptr;                           //jak dostaniemy pustą listę to zwracamy null
    node *sorted = first;
    node *notSorted = first->next;                                  //rozdzielamy na 2 listy posortowaną i nie posortowaną
    sorted->next = nullptr;
    while (notSorted != nullptr) {                                  //sortujemy dopoki istnieje lista nieposortowana
        node *tmp = notSorted;
        notSorted = notSorted->next;                               //tmp żeby 'nie zgubić' nieposortowanej listy
        insert(sorted, tmp);
    }
    return sorted;
}

void selectSort(int N, int tab[]) {
    for (int i = 0; i < N - 1; i++) {
        int min = i;
        for (int j = i + 1; j < N; j++) {
            if (tab[j] < tab[min])
                min = j;
        }
        int tmp = tab[i];
        tab[i] = tab[min];
        tab[min] = tmp;
    }
}


int main() {
    int t[10];
    for (int i = 0; i < 10; i++) {
        cin>>t[i];
    }
    selectSort(10,t);
    for (int i = 0; i < 10; i++) {
        cout<<t[i]<<" ";
    }
    return 0;
}