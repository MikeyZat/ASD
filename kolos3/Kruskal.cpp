//
// Created by mikey on 04.06.2019.
//

struct Node {
    int weight;
    int verticle;
    Node* next;
};

struct Union{
    Union* parent;
    int value;
    int rank;
};

Union* find(Union* x){
    while(x->parent!= nullptr){
        return find(x->parent);
    }
    return x;
}

void unify(Union* a, Union* b){
    Union* parent_a = find(a);
    Union* parent_b = find(b);
    if(parent_a->rank < parent_b->rank){
        parent_a->parent = parent_b;
    }else{
        parent_b->parent = parent_a;
    }
    if( parent_a->rank == parent_b->rank ){
        parent_a->rank++;
    }
}

Result* Kruskal (Node** Edges,int n) {
    Union** sets = new *Union;
    for(int i=0; i<n; i++){
        sets[i] = new Union;            //initialize sets
        sets[i]->parent = nullptr;
        sets[i]->rank = 0;
        sets[i]->value = i;
    }
    Heap heap = new Heap;
    for(int i=0; i<0;i++){
        while(Edges[i]->next) {
            heap.push( < i, Edges[i]->verticle, Edges[i]->weight);
            remove(Edges[Edges[i]->verticle], i);
            Edges[i]=Edges[i]->next;
        }
    }
    heap.init();
    int i = 0;
    int sum = 0;
    while(i<n-1){
        Edge* edge= heap.pop();
        if(find(edge->u) != find(edge->v)){
            i++;
            result.add(edge->u,edge->v,edge->weight);
            unify(sets[edge->u],sets[edge->v]);
            sum+=weight;
        }
    }
    return result;

}