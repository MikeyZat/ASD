//
// Created by mikey on 02.04.2019.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>

using namespace std;






int solveZad2(int *tab, int N, int sum) {
    int counter = 0;

    unordered_map<int, int> map;

    for (int i = 0; i < N; i++) {
        auto tmp = map.find(sum-tab[i]);
        if(tmp != map.end()){
            counter+=tmp->second;
        }
        map[tab[i]]++;
    }

    return counter;
}

void zad2() {
    int t[10] = {2, 5, 3, 7, 7, 2, 7, 2, 9, 1};
    cout << solveZad2(t,10,8);
}

int main() {


    return 0;
}
