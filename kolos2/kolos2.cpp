//
// Created by mikey on 13.05.2019.
//


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;


struct HuntingList {
    HuntingList *next;
    int predator;
    int prey;
};

struct Node {
    Node *next;
    int key;
};

void insertToList(Node **list, int index, int key) {
    Node *node = new Node;
    node->next = nullptr;
    node->key = key;
    if (list[index] == nullptr) {
        list[index] = node;
        return;
    }
    Node *tmp = list[index];
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = node;
}

void release_hunters(int index, Node **my_prey, Node **hunting_me, bool *isReleased, int &pokemon_order,
                     int *release_order) {
    int j = 2;
    Node *tmp = my_prey[index];
    while (j > 0 && tmp != nullptr) {
        if (isReleased[tmp->key])
            j--;
        tmp = tmp->next;
    }
    if (j > 0)
        return;

    isReleased[index] = true;
    release_order[pokemon_order++] = index;
    tmp = hunting_me[index];
    while (tmp != nullptr) {
        release_hunters(tmp->key, my_prey, hunting_me, isReleased, pokemon_order, release_order);
        tmp = tmp->next;
    }
}

int *releaseThemAll(HuntingList *list, int n) {
    Node **my_prey = new Node *[n];
    Node **hunting_me = new Node *[n];
    bool *isReleased = new bool[n];
    int *release_order = new int[n];
    for (int i = 0; i < n; i++) {
        my_prey[i] = hunting_me[i] = nullptr;
        isReleased[i] = false;
        release_order[i] = -1;
    }
    HuntingList *tmp = list;
    while (tmp != nullptr) {
        insertToList(my_prey, tmp->predator, tmp->prey);
        insertToList(hunting_me, tmp->prey, tmp->predator);
        tmp = tmp->next;
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (my_prey[i] == nullptr) {
            release_order[j++] = i;
            isReleased[i] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!isReleased[i])
            release_hunters(i, my_prey, hunting_me, isReleased, j, release_order);
    }

    for (int i = 0; i < n; i++) {
        if (release_order[i] == -1)
            return nullptr;
    }

    return release_order;

}


HuntingList *preparePokemons() {
    HuntingList *first = new HuntingList;
    first->predator = 1;
    first->prey = 1;
    HuntingList *tmp2 = new HuntingList;
    first->next = tmp2;
    tmp2->predator = 1;
    tmp2->prey = 1;
    HuntingList *tmp1 = tmp2;
    tmp2 = new HuntingList;
    tmp2->predator = 1;
    tmp2->prey = 1;
    tmp1->next = tmp2;
    tmp1 = tmp2;
    tmp2 = new HuntingList;
    tmp2->predator = 1;
    tmp2->prey = 1;
    tmp1->next = tmp2;
    tmp1 = tmp2;
    tmp2 = new HuntingList;
    tmp2->predator = 1;
    tmp2->prey = 1;
    tmp1->next = tmp2;
    tmp1 = tmp2;
    tmp2 = new HuntingList;
    tmp2->predator = 1;
    tmp2->prey = 1;
    tmp1->next = tmp2;
    tmp2->next = nullptr;
    return first;
}

struct HT {
    int *table;
    int size;
};

int hashx(int x) {
    return (x * 2137) % 113;
}

void enlrage(HT *ht) {
    HT *newHT = new HT;
    newHT->table = new int[ht->size * 2];
    newHT->size = ht->size * 2;
//    for (int i = 0; i < ht->size; i++) {
//        if (hashx(ht->table[i]) == i)
//    }
}


int main() {


    return 0;
}