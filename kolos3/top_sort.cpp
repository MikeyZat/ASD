//
// Created by mikey on 04.06.2019.
//

node *topsort(node **G, int n) {
    int *color = new int[n];
    for (int i = 0; i < n; i++, color[i] = 0);
    node *first = NULL;

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs_visit(G, n, color, i, first);
        }
    }
    delete[] color;
    return first;
}

void dfs_visit(node **G, int n, int *color, int u, node **first) {
    color[u] = 1;
    for (node *tmp = G[u]; tmp != NULL; tmp = tmp->next) {
        if (color[tmp->w] == 0) {
            dfs_visit(G, n, color, p->w, &first);
        }
    }
    color[u] = 2;
    node *tmp = new node;
    tmp->w = u;
    tmp->next = first;
    first = tmp;

}