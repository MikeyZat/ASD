//
// Created by mikey on 04.06.2019.
//

void BellmanFord(Node* edges, int n, int start, int end){
    int* distances = new int[n];
    for(int i=0; i<n; i++){
        distances[i] = MAX_INT;
    }
    distances[start] = 0;
    for(int i=1; i<n;i++){
        for(Node* tmp = edges; tmp!= nullptr; tmp=tmp->next){
            if(distances[tmp->v] > distances[tmp->u] + tmp->weight){
                distances[tmp->v] > distances[tmp->u] + tmp->weight;
            }
        }
    }
    for(Node* tmp = edges; tmp!= nullptr; tmp=tmp->next){
        if(distances[tmp->v] > distances[tmp->u] + tmp->weight){
            cout<<"UJEMNY CYKL";
        }
    }
    cout<<distances[end];
}