def fatorial(n:int):
    produto=1
    
    for valor in range(n-1, 0,-1):
        produto+= produto * valor 
    
    return(produto)        

print(fatorial(int(input())))
    