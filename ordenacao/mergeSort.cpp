#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class MergeSort {
private:
    int max;

public:
    MergeSort(int m) { max = m; }
    void merge(int array[], int const left, int const mid, int const right) {
        int const subArrayOne = mid - left + 1;
        int const subArrayTwo = right - mid;

        auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = array[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = array[mid + 1 + j];

        auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;

        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            } else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }

        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
        delete[] leftArray;
        delete[] rightArray;
    }

    void mergeSort(int array[], int const begin, int const end) {
        if (begin >= end)
            return;

        int mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
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

    MergeSort *ms = new MergeSort(TAM);

    cout << "Vetor Original (10 primeiros elementos)\n";
    ms->impVetor(vetor);

    clock_t start = clock();
    ms->mergeSort(vetor, 0, TAM - 1);
    clock_t end = clock();

    cout << "\nVetor Ordenado (Merge Sort - 10 primeiros elementos)\n";
    ms->impVetor(vetor);

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nTempo gasto pelo Merge Sort: " << time_taken << " segundos\n";

    delete[] vetor;
    delete ms;

    return 0;
}
