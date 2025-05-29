from random import randint
TAM = 50000

arquivo = "script.txt"
arq = open(arquivo, 'w')

for i in range(TAM):
    numero = randint(1, 90000)
    if i == TAM - 1:
        arq.write(f"{numero}")
    else:
        arq.write(f"{numero}, ")

arq.close()