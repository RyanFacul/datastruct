#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class InsertionSort {
private:
    int MAX;

public:
    InsertionSort(int m) { MAX = m; }
    void insertionSort(int v[]) {
        int i, j, x;
        for (i = 1; i < MAX; i++) {
            x = v[i];
            j = i - 1;
            while ((j >= 0) && (x < v[j])) {
                v[j + 1] = v[j];
                j = j - 1;
            }
            v[j + 1] = x;
        }
    }

    void impVetor(int *v) {
        cout << "{ ";
        for (int i = 0; i < 10; i++) { // Mostra só os 10 primeiros
            cout << v[i] << " ";
        }
        cout << "...}\n\n"; // Indicando que o vetor continua
    }
};

int main() {
    const int TAM = 100000;
    int *vetor = new int[TAM];

    srand(time(0));
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % TAM; // Elementos de 0 a 100000
    }

    InsertionSort *is = new InsertionSort(TAM);

    cout << "Vetor Original (10 primeiros elementos)\n";
    is->impVetor(vetor);

    clock_t start = clock();
    is->insertionSort(vetor);
    clock_t end = clock();

    cout << "\nVetor Ordenado (Insertion Sort - 10 primeiros elementos)\n";
    is->impVetor(vetor);

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nTempo gasto pelo Insertion Sort: " << time_taken << " segundos\n";

    delete[] vetor;
    delete is;

    return 0;
}
