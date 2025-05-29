#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // Biblioteca do Windows para alta precisão
#define TAM 50000

void mergeSort(int vet[], int inicio, int fim);
void intercala(int vet[], int inicio, int meio, int fim);

int main() {
    int vet[TAM] = {10, 9, 100, 900, 289};

    LARGE_INTEGER inicio, fim, freq;
    double tempo_execucao;

    QueryPerformanceFrequency(&freq);     // Frequência do contador
    QueryPerformanceCounter(&inicio);     // Tempo inicial

    mergeSort(vet, 0, TAM - 1);

    QueryPerformanceCounter(&fim);        // Tempo final

    tempo_execucao = (double)(fim.QuadPart - inicio.QuadPart) / freq.QuadPart;


    printf("\nTempo de execução: %.9f segundos\n", tempo_execucao);

    return 0;
}

void mergeSort(int vet[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        intercala(vet, inicio, meio, fim);
    }
}

void intercala(int vet[], int inicio, int meio, int fim) {
    int inicio1 = inicio;
    int inicio2 = meio + 1;
    int posLivre = 0;
    int vetAux[TAM];

    while (inicio1 <= meio && inicio2 <= fim) {
        if (vet[inicio1] <= vet[inicio2]) {
            vetAux[posLivre++] = vet[inicio1++];
        } else {
            vetAux[posLivre++] = vet[inicio2++];
        }
    }

    while (inicio1 <= meio) {
        vetAux[posLivre++] = vet[inicio1++];
    }

    while (inicio2 <= fim) {
        vetAux[posLivre++] = vet[inicio2++];
    }

    for (int i = 0; i < posLivre; i++) {
        vet[inicio + i] = vetAux[i];
    }
}
