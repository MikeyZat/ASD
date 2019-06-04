//
// Created by mikey on 04.06.2019.
//

struct Edge {
    int u;
    int v;
    int weight;
};


void Prim(Node **edges, int n) {
    Heap heap = new Heap;
    bool *visited = new bool;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int i = 0;
    int sum = 0;
    while (i < n) {
        while (edges[i] != nullptr) {
            Node *edge = new Node;
            edge->verticle = edges[i]->verticle;
            edge->weight = edges[i]->weight;
            heap.push(edge);
            edges[i] = edges[i]->next;
        }
        visited[i] = true;
        Node* edge = heap.pop();
        while(visited[edge->verticle]){
            heap.heapify();
            edge = heap.pop();
        }
        sum+=edge->weight;
        i++;
    }
}
