#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class SelectionSort {
private:
    int MAX;

public:
    SelectionSort(int m) { MAX = m; }
    void selection_sort(int num[], int tam) {
        int i, j, min, aux;
        for (i = 0; i < (tam - 1); i++) {
            min = i;
            for (j = (i + 1); j < tam; j++) {
                if (num[j] < num[min])
                    min = j;
            }
            if (i != min) {
                aux = num[i];
                num[i] = num[min];
                num[min] = aux;
            }
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

    SelectionSort *ss = new SelectionSort(TAM);

    cout << "Vetor Original (10 primeiros elementos)\n";
    ss->impVetor(vetor);

    clock_t start = clock();
    ss->selection_sort(vetor, TAM);
    clock_t end = clock();

    cout << "\nVetor Ordenado (Selection Sort - 10 primeiros elementos)\n";
    ss->impVetor(vetor);

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nTempo gasto pelo Selection Sort: " << time_taken << " segundos\n";

    delete[] vetor;
    delete ss;

    return 0;
}
