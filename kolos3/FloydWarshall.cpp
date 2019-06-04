//
// Created by mikey on 04.06.2019.
//

int **FloydWarshall(int **weights, int n) {
    int **result = new * int[n];
    for (int i = 0; i < n; i++) {
        result[i] = new int[n];
        for (int j = 0; j < n; j++) {
            result[i][j] = weights[i][j];
        }
    }
    for (int t = 0; t < n; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = min(result[i][j], results[i][t] + result[t][j]);
            }
        }
    }
    return result;

}