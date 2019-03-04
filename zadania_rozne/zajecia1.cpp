//
// Created by mikey on 02.03.2019.
//
#include <iostream>
#include <vector>

using namespace std;

const int k = 3;
const int N = 9;
const int SIZE = 11;
struct minMax {
    int min;
    int max;
};

struct twoNum {
    int num1;
    int num2;
};

minMax *findMinMax(int N, int t[]) {
    int max;
    int min;
    min = max = t[0];
    for (int i = 0; i < N - 1; i += 2) {
        if (t[i] < t[i + 1]) {
            if (t[i + 1] > max)
                max = t[i + 1];
            if (t[i] < min)
                min = t[i];
        } else {
            if (t[i] > max)
                max = t[i];
            if (t[i + 1] < min)
                min = t[i + 1];
        }
    }
    minMax *result = new minMax;
    result->max = max;
    result->min = min;
    return result;
}

bool findSum(int N, int t[], int sum, twoNum *&result) {
    int first = 0;
    int last = N - 1;
    while (first != last) {
        if (t[first] + t[last] < sum)
            first++;
        else if (t[first] + t[last] > sum)
            last--;
        else {
            result->num1 = t[first];
            result->num2 = t[last];
            return true;
        }
    }
    return false;
}

struct node {
    node *next;
    int value;
};

void printList(node *first) {
    while (first != nullptr) {
        cout << first->value << " ";
        first = first->next;
    }
    cout << endl;
}

node *createList() {
    node *first = new node;
    first->value = 45;
    first->next = nullptr;
    node *firstC = first;
    for (int i = 0; i < 10; i++) {
        node *newEl = new node;
        newEl->value = 100 - i * 2;
        newEl->next = nullptr;
        first->next = newEl;
        first = newEl;
    }
    return firstC;
}

node *revertList(node *first) {
    node *reverse = nullptr;
    while (first != nullptr) {
        node *tmp = reverse;
        reverse = first;
        first = first->next;
        reverse->next = tmp;
    }
    return reverse;
}

void heapifyMax(int t[], int i) {       //heapify z wykładu (naprawianie kopca)
    int left = i * 2;                   //kto nie uważał na wykłądzie (jak ja) polecam stronkę
    int right = i * 2 + 1;              // http://informatyka.wroc.pl/node/433?page=0,2
    int largest;
    int SIZE = t[0];
    if (left < SIZE + 1 && t[left] > t[i])
        largest = left;
    else
        largest = i;
    if (right < SIZE + 1 && t[right] > t[largest])
        largest = right;
    if (largest != i) {
        int pom = t[i];
        t[i] = t[largest];
        t[largest] = pom;
        heapifyMax(t, largest);
    }

}

void heapifyMin(int t[], int i) {
    int left = i * 2;
    int right = i * 2 + 1;
    int largest;
    int SIZE = t[0];
    if (left < SIZE + 1 && t[left] < t[i])
        largest = left;
    else
        largest = i;
    if (right < SIZE + 1 && t[right] < t[largest])
        largest = right;
    if (largest != i) {
        int pom = t[i];
        t[i] = t[largest];
        t[largest] = pom;
        heapifyMax(t, largest);
    }
}

void buildHeapMax(int t[]) {        //budowanie kopca max
    int SIZE = t[0];
    for (int i = SIZE / 2; i >= 1; i--) {
        heapifyMax(t, i);
    }
}

void buildHeapMin(int t[]) {            //budowanie kopca min
    int SIZE = t[0];
    for (int i = SIZE / 2; i >= 1; i--) {
        heapifyMin(t, i);
    }
}


struct position {       //struktura potrzebna do zadania drugiego
    int value;
    int array;
    int index;
};


void helpHeapifyMin(position t[], int i) {      //to samo co wyżej tylko żeby działało na strukturze
    int left = i * 2;
    int right = i * 2 + 1;
    int largest;
    int SIZE = t[0].value;
    if (left < SIZE + 1 && t[left].value < t[i].value)
        largest = left;
    else
        largest = i;
    if (right < SIZE + 1 && t[right].value < t[largest].value)
        largest = right;
    if (largest != i) {
        position pom = t[i];
        t[i] = t[largest];
        t[largest] = pom;
        helpHeapifyMin(t, largest);
    }
}


void helpBuildHeapMin(position t[]) {       //to samo co wyżej tylko żeby działało na strukturze
    int SIZE = t[0].value;
    for (int i = SIZE / 2; i >= 1; i--) {
        helpHeapifyMin(t, i);
    }
}

void zajeciaDrugieZad2() {
    vector<int> tab[k];
    tab[0].push_back(1);
    tab[0].push_back(3);
    tab[1].push_back(2);
    tab[1].push_back(4);
    tab[1].push_back(6);                    //wartości początkowe 3 tablic
    tab[2].push_back(0);
    tab[2].push_back(9);
    tab[2].push_back(10);
    tab[2].push_back(11);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < tab[i].size(); j++) {
            cout << tab[i][j] << " ";                   //wypisanie początkowych tablic
        }
        cout << endl;
    }
    int output[N] = {0};                                //nasz wynik
    position heap[k + 1] = {0};                         //tworzymy k-elementwoy kopiec
    heap[0].value = k;                                  //rozmiar kopca k
    for (int i = 1; i <= k; i++) {
        heap[i].value = tab[i - 1][0];
        heap[i].array = i - 1;                          //musimy zapamiętać z której tablicy
        // i z którego miejsca bierzemy dany element
        heap[i].index = 0;
    }
    helpBuildHeapMin(heap);                         //budujemy kopiec_min z pierwszych elementów każdej tablicy
    int i = 0;
    while (heap[0].value > 0) {
        output[i] = heap[1].value;                  //1 element wpisujemy do tablicy jest to nasze minimum
        i++;
        int arr = heap[1].array;
        int index = heap[1].index;
        if (index + 1 < tab[arr].size()) {          //do kopca wstawiamy kolejny element z tablicy z której
            heap[1].value = tab[arr][index + 1];    //był element wzięty do naszego wyniku
            heap[1].array = arr;
            heap[1].index = index + 1;
        } else {
            heap[1] = heap[heap[0].value];          //jeśli ta tablica się skończyła zmniejszamy kopiec o 1
            heap[0].value--;                        //i jako 1 element wstawiamy ostatni element kopca
        }
        helpHeapifyMin(heap, 1);                    //po każdej iteracji naprawiamy kopiec log(k)

    }                                               // N iteracji * log(k) naprawień kopca = N*log(k)
    for (int i = 0; i < N; i++) {
        cout << output[i] << " ";
    }
}
//drobna dygresja - dlaczego to działa?
// kolejny element do naszego wyniku możemy wybrać jedynie spośród pierwszych z pozostałych elementów
// tablic ( ponieważ są posortowane) Naturalnie przeiterowalibyśmy i znaleźli minimum i je wybrali
// złożoność wynosiłaby N*K, jednak trzymanie pierwszych elementów tablic jako kopca
// umożliwia znajdywanie minimum w czasie jednostkowym. Jedynie utrzymanie kopca to log(k)
// ale mimo wszystko warto.
// Wnioski: Kopiec jest warty uwagi jeśli będziemy znajdywać minimum
// danych elementów zbioru wiele razy, zbudowanie go kosztuje na ogół N, ale utrzymanie jedynie log(N)

int main() {
    zajeciaDrugieZad2();
}