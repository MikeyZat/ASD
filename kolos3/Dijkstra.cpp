//
// Created by mikey on 04.06.2019.
//
int min(int *dist, bool visited, int n) {
    int min_i = 0;
    for (int i = 0; i < n; i++) {
        if (dist[min_i] > dist[i])
            min_i = i;
    }
    return min_i;
}

const MAX_INT = 1248124;

int Dijkstra(int **weights, int n, int start, int end) {
    int *distances = new int;
    bool* visited = new bool;
    for (int i = 0; i < n; i++) {
        distances[i] = MAX_INT;
    }
    distances[start] = 0;
    int curr_i = min(distances, visited, n);
    while(curr_i != end){
        for (int i = 0; i < n; i++) {
            if (weights[curr_i][i] > 0) {
                if (!visited[i] && distances[i] > distances[curr_i] + weights[curr_i][i]) {
                    distances[i] = distances[curr_i] + weights[curr_i][i];
                }
            }
        }
        visited[i] = true;
        curr_i = min(distances, visited, n);
    }
    int result = distances[curr_i];
    delete [] distances;
    delete [] visited;
    return result;
}