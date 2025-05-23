import time

def intercala(inicio, meio, fim, X):
    aux = [0] * (fim - inicio + 1)
    inicio_v01 = inicio
    inicio_v02 = meio + 1
    poslivre = 0

    while inicio_v01 <= meio and inicio_v02 <= fim:
        if X[inicio_v01] <= X[inicio_v02]:
            aux[poslivre] = X[inicio_v01]
            inicio_v01 += 1
        else:
            aux[poslivre] = X[inicio_v02]
            inicio_v02 += 1
        poslivre += 1

    while inicio_v01 <= meio:
        aux[poslivre] = X[inicio_v01]
        inicio_v01 += 1
        poslivre += 1

    while inicio_v02 <= fim:
        aux[poslivre] = X[inicio_v02]
        inicio_v02 += 1
        poslivre += 1

    for i in range(len(aux)):
        X[inicio + i] = aux[i]

def mergesort(inicio, fim, v):
    if inicio < fim:
        meio = (inicio + fim) // 2
        mergesort(inicio, meio, v)
        mergesort(meio + 1, fim, v)
        intercala(inicio, meio, fim, v)


vetor = []

inicio_tempo = time.time()
mergesort(0, len(vetor) - 1, vetor)
fim_tempo = time.time()

print("Vetor ordenado:")
print(vetor)
print(f"\nTempo de execução: {fim_tempo - inicio_tempo:.6f} segundos")