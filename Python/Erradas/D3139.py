def calcularDiasMeta(valorInicial:int,valorMeta:int,inscricoesDiarias:list[int]):
    
    valorAtingido =valorInicial #valor atingido começa com o inicial
    
    for i in range(len(inscricoesDiarias)):
        valorAtingido +=inscricoesDiarias[i] #Aumentamos o valor atingido por dia

        if valorAtingido >= valorMeta: #Checa se a meta foi atendida
            return i+1 # Retorna o dia que a meta será atendida
    
    return len(inscricoesDiarias)

inicio, meta = list(map(int, input().split()))
inscricoes= list(map(int, input().split()))

print(calcularDiasMeta(inicio,meta,inscricoes))