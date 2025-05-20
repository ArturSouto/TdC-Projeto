from random import randint
TAM = 1000

arquivo = "script.txt"
arq = open(arquivo, 'w')

for i in range(TAM):
    numero = randint(10000, 100000)
    if i == TAM - 1:
        arq.write(f"{numero}")
    else:
        arq.write(f"{numero}, ")

arq.close()