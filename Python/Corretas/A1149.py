# Faça um algoritmo para ler um valor A e um valor N. Imprimir a soma de A + i para cada i com os valores (0 <= i <= N-1). Enquanto N for negativo ou ZERO, um novo N(apenas N) deve ser lido.

valoresRecebidos= list(map(int, input().split()))

A, valoresN= valoresRecebidos[0], valoresRecebidos[1:]


soma= 0

for N in valoresN:
    if N > 0:
        for i in range(N):
            soma += A + i

print(soma)