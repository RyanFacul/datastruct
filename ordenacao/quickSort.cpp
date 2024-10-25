#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class QuickSort {
private:
    int max;

public:
    QuickSort(int m) { max = m; }
    void quicksort(int values[], int began, int end) {
        int i, j, pivo, aux;
        i = began;
        j = end - 1;
        pivo = values[(began + end) / 2];
        while (i <= j) {
            while (values[i] < pivo && i < end) {
                i++;
            }
            while (values[j] > pivo && j > began) {
                j--;
            }
            if (i <= j) {
                aux = values[i];
                values[i] = values[j];
                values[j] = aux;
                i++;
                j--;
            }
        }
        if (j > began)
            quicksort(values, began, j + 1);
        if (i < end)
            quicksort(values, i, end);
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

    QuickSort *qs = new QuickSort(TAM);

    cout << "Vetor Original (10 primeiros elementos)\n";
    qs->impVetor(vetor);

    clock_t start = clock();
    qs->quicksort(vetor, 0, TAM);
    clock_t end = clock();

    cout << "\nVetor Ordenado (Quick Sort - 10 primeiros elementos)\n";
    qs->impVetor(vetor);

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nTempo gasto pelo Quick Sort: " << time_taken << " segundos\n";

    delete[] vetor;
    delete qs;

    return 0;
}
