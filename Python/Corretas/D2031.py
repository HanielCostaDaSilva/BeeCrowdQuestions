VencedorDict={
    'pedra':'papel',
    'ataque':'pedra papel',
}

def checarVencedor(jogada1, jogada2):
    if jogada1 == 'papel' == jogada2:
        return "Ambos venceram"
    
    elif jogada1 == 'ataque' == jogada2:
        return "Aniquilacao mutua"
    
    elif jogada1 == jogada2:
        return "Sem ganhador"
    
    condicaoVitoria1= VencedorDict.get(jogada1,'papel').split()
    condicaoVitoria2= VencedorDict.get(jogada2,'papel').split()
    
    if  condicaoVitoria1.count(jogada2):
        return "Jogador 1 venceu"
    
    elif condicaoVitoria2.count(jogada1):
        return "Jogador 2 venceu"
    
    
repeticoes=int(input())

for i in range(repeticoes):
    j1 = input()
    j2= input()
    print(checarVencedor(j1,j2))