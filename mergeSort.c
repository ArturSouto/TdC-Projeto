#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100

void mergeSort(int vet[], int inicio, int fim);
void intercala(int vet[], int inicio, int meio, int fim);

int main() {
    int vet[TAM] = {26731, 35312, 43049, 24230, 20151, 13759, 22060, 40847, 12315, 27896, 21658, 40818, 22146, 40164, 14630, 10291, 34730, 36858, 32786, 28363, 36570, 39286, 33520, 49536, 24446, 22001, 10304, 29781, 25652, 45846, 35036, 10822, 14084, 49498, 49985, 10488, 36006, 17040, 18551, 49593, 46507, 32079, 25340, 12744, 23144, 27944, 37339, 23174, 17635, 44510, 31562, 28829, 47922, 36116, 44576, 18196, 24567, 32485, 15080, 13576, 40379, 40421, 46591, 39896, 19230, 28178, 22799, 26496, 40889, 16714, 39350, 14962, 16265, 31740, 44213, 47368, 25310, 23585, 12774, 36437, 36237, 48204, 41028, 12934, 11766, 13155, 27780, 39482, 33849, 29013, 17447, 33252, 24902, 12809, 16115, 34061, 22054, 37348, 33404, 24120};
    
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();
    mergeSort(vet, 0, TAM - 1);
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\n\nSeu vetor organizado:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d\n", vet[i]);
    }

    printf("\nTempo de execução: %.6f segundos\n", tempo_execucao);

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

    for (inicio1 = inicio; inicio1 <= fim; inicio1++) {
        vet[inicio1] = vetAux[inicio1 - inicio];
    }
}
