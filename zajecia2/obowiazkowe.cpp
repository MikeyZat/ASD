//
// Created by mikey on 05.03.2019.
//
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int k = 3;
const int N = 9;

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

void zad2() {
    vector<int> tab[k];
    tab[0].push_back(1);
    tab[0].push_back(3);
    tab[1].push_back(2);
    tab[1].push_back(4);
    tab[1].push_back(6);                    //wartości początkowe 3 tablic
    tab[2].push_back(0);
    tab[2].push_back(9);                    //ignore this
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

int merge(int t[], int first, int mid, int last) {
    int result = 0;
    int *tp = new int[last - first + 1];
    int i = first;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= last) {
        if (t[i] < t[j]) tp[k++] = t[i++];
        else {
            tp[k++] = t[j++];
            result += mid + 1 - i;                  //all elements in the left table makes inversion with
        }                                           //the element from the right table which is greater than all of them
    }
    while (i <= mid)tp[k++] = t[i++];
    while (j <= last)tp[k++] = t[j++];
    for (int c = 0; c < last - first + 1; c++) {
        t[first + c] = tp[c];
    }
    delete[] tp;
    return result;
}


int mergeSort(int t[], int first, int last) {
    int mid;
    int result = 0;
    if (first != last) {
        mid = (first + last) / 2;
        result += mergeSort(t, first, mid);
        result += mergeSort(t, mid + 1, last);
        result += merge(t, first, mid, last);
    }
    return result;
}

void zad4() {
    int t[5];
    t[0] = 3;
    t[1] = 1;               //initial data
    t[2] = 5;
    t[3] = 7;
    t[4] = 4;
    for (int i = 0; i < 5; i++) cout << t[i] << " ";
    cout << endl;
    int result = mergeSort(t, 0, 4);
    for (int i = 0; i < 5; i++) cout << t[i] << " ";
    cout << endl << result;
}


void listMerge(node *first, node *mid, node *&head) {
//    cout<<"lacze: "<<endl;
//    printList(first);             uncomment this to see live
//    printList(mid);
    node *newList = new node;
    node *newListC = newList;
    newList->next = nullptr;
    node *i = first;
    node *j = mid;
    while (i != nullptr || j != nullptr) {
        if (i == nullptr) {
            newList->next = j;
            break;
        }
        if (j == nullptr) {
            newList->next = i;
            break;
        }
        if (i->value < j->value) {
            newList->next = i;
            i = i->next;
            newList = newList->next;
            newList->next = nullptr;
        } else {
            newList->next = j;
            j = j->next;
            newList = newList->next;
            newList->next = nullptr;
        }
    }
    head = newListC->next;
    delete newListC;
}

//
void listMergeSort(node *&first) {
    if (first->next != nullptr) {
        node *mid = first;
        node *last = first;
        while (last->next != nullptr && last->next->next != nullptr) {
            mid = mid->next;
            last = last->next->next;
        }
        node *tmp = mid->next;
        mid->next = nullptr;
//        cout << "dziele na "<<endl;
//        printList(first);                 uncomment this to see live
//        printList(tmp);
        listMergeSort(first);
        listMergeSort(tmp);
        listMerge(first, tmp, first);
    }
}

node *createList() {
    srand(time(NULL));
    node *first = new node;
    first->value = rand() % 100;
    first->next = nullptr;
    node *firstC = first;
    for (int i = 0; i < 10; i++) {
        node *newEl = new node;
        newEl->value = rand() % 100;
        newEl->next = nullptr;
        first->next = newEl;
        first = newEl;
    }
    return firstC;
}


void zad1() {
    node *first = createList();
    printList(first);
    listMergeSort(first);
    printList(first);

}

int main() {
    zad1();
}