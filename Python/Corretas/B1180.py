#Faça um programa que leia um valor N. Este N será o tamanho de um vetor X[N]. A seguir, leia cada um dos valores de X, encontre o menor elemento deste vetor e a sua posição dentro do vetor, mostrando esta informação.

def encontrar(listaInteiro:list[int]):
    menor=listaInteiro[0]
    posicaoMenor=1
    for i in range(1,len(listaInteiro)):
        
        if menor > listaInteiro[i]:
        
            menor=listaInteiro[i]
            posicaoMenor= i
    
    return (menor, posicaoMenor)
        
valorQuantidade = int(input())      
menor,posicao= encontrar(list(map( int,input().split() )) )

print(f"Menor valor: {menor} Posicao: {posicao}")