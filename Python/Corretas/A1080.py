maior=0
for i in range(100):
    numeroComparar= int(input())
    if numeroComparar > maior or i == 0:
        maior=numeroComparar
        posicaoMaiorValor = i+1

print(maior)
print(posicaoMaiorValor)