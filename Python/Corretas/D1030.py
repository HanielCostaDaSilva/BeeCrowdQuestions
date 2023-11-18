def josephus(quantidadePessoas, saltos):
    posicaoSobrevivente = 0
    primeiroSuicidar=2
    for i in range(primeiroSuicidar, quantidadePessoas + 1):
        posicaoSobrevivente = (posicaoSobrevivente + saltos) % i
    return posicaoSobrevivente + 1

testesQuantidade = int(input())

for caso in range(1, testesQuantidade + 1):
    n, k = map(int, input().split())
    sobrevivente = josephus(n, k)
    print(f"Case {caso}: {sobrevivente}")
