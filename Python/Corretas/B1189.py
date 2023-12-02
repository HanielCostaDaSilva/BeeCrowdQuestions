matriz = [[0 for col in range(12)] for row in range(12)]

o = input()

for i in range(12):
    for j in range(12):
        matriz[i][j] = float(input())

soma = 0.0

for i in range(1, 11):
    if (i < 6): # Sobe
        for j in range(0, i):
            soma += matriz[i][j]
    else: #desce
        for j in range((len(matriz) - i) - 1):
            soma += matriz[i][j]

if o == "S":
    print(f'{soma:.1f}')

if o == "M":
    media = soma / (10+8+6+4+2)  # Quadros que vai ser feita a operação
    print(f'{media:.1f}')

''' 
     0 1 2 3 4 5 6 7 8 9 10 11 
    0[0 0 0 0 0 0 0 0 0 0 0 0]
    1[X 0 0 0 0 0 0 0 0 0 0 0]
    2[X X 0 0 0 0 0 0 0 0 0 0]
    3[X X X 0 0 0 0 0 0 0 0 0]
    4[X X X X 0 0 0 0 0 0 0 0]
    5[X X X X X 0 0 0 0 0 0 0]
    6[X X X X X 0 0 0 0 0 0 0]
    7[X X X X 0 0 0 0 0 0 0 0]
    8[X X X 0 0 0 0 0 0 0 0 0]
    9[X X 0 0 0 0 0 0 0 0 0 0]
    0[X 0 0 0 0 0 0 0 0 0 0 0] 
    1[0 0 0 0 0 0 0 0 0 0 0 0]

    if (i < 6): # Sobe
        for j in range( - 1, ( -(i + 1 )), - 1):
            soma+= matriz[i][j]

    else:  # Desce
'''
