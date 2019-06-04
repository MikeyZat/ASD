//
// Created by mikey on 04.06.2019.
//

struct node {
    int color; // 0
    int v;
    int d;  //0
    int low;    //0
    node *next;
    int par;    // -1
};

bool bridges(node **G, int n) {
    int time = 0;
    return dfsvisit(G, n, 0, time);
}

bool dfsvisit(node **G, int n, int u, int& time){
    G[u]->color = 1;
    G[u]->d = ++time;
    G[u]->low = time;
    for(node* tmp = G[u]; tmp!= nullptr; tmp=tmp->next){
        if(G[tmp->v]->color == 0){
            G[tmp->v]->par = u;
            if(dfsvisit(G,n,tmp->v,time)) return true;
            G[u]->low = min(G[u]->low,G[tmp->v]->low);
        }
        if(G[u]->par == tmp->v){
            G[u]->low = min(G[u]->low, G[tmp->v]->d);
        }
    }
    G[u]->color = 2;
    return (G[u]->low == G[u]->d && G[u]->par != -1);
    }


}