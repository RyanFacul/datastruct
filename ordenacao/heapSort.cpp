#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class HeapSort {
private:
    int max;

public:
    HeapSort(int m) { max = m; }
    void impVetor(int *v) {
        cout << "{ ";
        for (int i = 0; i < 10; i++) { // Mostra só os 10 primeiros
            cout << v[i] << " ";
        }
        cout << "...}\n\n"; // Indicando que o vetor continua
    }

    void heapsort(int a[], int n) {
        int i = n / 2, pai, filho, t;
        while (true) {
            if (i > 0) {
                i--;
                t = a[i];
            } else {
                n--;
                if (n <= 0)
                    return;
                t = a[n];
                a[n] = a[0];
            }
            pai = i;
            filho = i * 2 + 1;
            while (filho < n) {
                if ((filho + 1 < n) && (a[filho + 1] > a[filho])) {
                    filho++;
                }
                if (a[filho] > t) {
                    a[pai] = a[filho];
                    pai = filho;
                    filho = pai * 2 + 1;
                } else {
                    break;
                }
            }
            a[pai] = t;
        }
    }
};

int main() {
    const int TAM = 100000;
    int *vetor = new int[TAM];

    srand(time(0));
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % TAM; // Elementos de 0 a 100000
    }

    HeapSort *hs = new HeapSort(TAM);

    cout << "Vetor Original (10 primeiros elementos)\n";
    hs->impVetor(vetor);

    clock_t start = clock();
    hs->heapsort(vetor, TAM);
    clock_t end = clock();

    cout << "\nVetor Ordenado (Heap Sort - 10 primeiros elementos)\n";
    hs->impVetor(vetor);

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nTempo gasto pelo Heap Sort: " << time_taken << " segundos\n";

    delete[] vetor;
    delete hs;

    return 0;
}
