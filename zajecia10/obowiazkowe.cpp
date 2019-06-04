//
// Created by mikey on 21.05.2019.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 10;

typedef pair<int, int> iPair;

struct node {
    node *parent;
    int rank;
    int weight;
    int u;
    int v;
};


node *Find(node *first) {
    while (first->parent != nullptr) {
        first = first->parent;
    }
    return first;
}

void Union(node *first, node *second) {
    node *first_p = Find(first);
    node *second_p = Find(second);

    if (first_p->rank > second_p->rank) {
        second_p->parent = first_p;
    } else {
        first_p->parent = second_p;
    }


    if (first_p->rank == second_p->rank)
        second_p->rank;
}


void zad2() {

    node **sets = new node *[N];
    for (int i = 0; i < N; i++) {
        int weight, u, v;
        cin >> weight >> u >> v;
        sets[i] = new node;
        sets[i]->parent = nullptr;
        sets[i]->rank = 0;
        sets[i]->u = u;
        sets[i]->v = v;
        sets[i]->weight = weight;
    }

    for(int i=0;i<N;i++){
        node* first= Find(sets[i]);
        node* second = Find(sets[i]);
    }
}

int main() {


    return 0;
}