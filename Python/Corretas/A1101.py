#Leia um conjunto não determinado de pares de valores M e N (parar quando algum dos valores for menor ou igual a zero). Para cada par lido, mostre a sequência do menor até o maior e a soma dos inteiros consecutivos entre eles (incluindo o N e M).

while True:
    try:
        M, N = map(int, input().split())

        soma=0

        valores=""

        if M < 1 or N < 1:
            pass

        elif N <= M:
            for i in range(N, M + 1):
                if i ==M:
                    valores += f'{i}'
                else:
                    valores += f'{i} '
                soma += i

        elif M < N:
            for i in range(M, N + 1):
                if i ==N:
                    valores += f'{i}'
                else:
                    valores += f'{i} '
                soma += i
        if valores:
            print(valores,f'Sum={soma}')
    except:
        break