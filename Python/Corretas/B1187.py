matriz=[[0 for col in range(12)] for row in range(12)]

o=input()

for i in range(12):
    for j in range(12):
        matriz[i][j] = float(input())

soma=0.0

for i in range(0,5):
    
    for j in range(i+1, ( (len(matriz)-1) -i)):
        
        soma+= matriz[i][j]


if o== "S":
    print(f'{soma:.1f}')
    
if o== "M":
    media= soma / (10+8+6+4+2) #Quadros que vai ser feita a operação
    print(f'{media:.1f}')