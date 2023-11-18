def checkOddOrEven(n:int):
    resultado=''
    if n==0: #Caso seja 0
        return "NULL"
    
    if n%2: #Caso seja odd
        resultado+="ODD"
    else: #Caso seja even
        resultado+="EVEN"
    
    if n>0:
        resultado+=" POSITIVE"
    else:
        resultado+=" NEGATIVE"
    return resultado
        
repeticoesQuant =int(input())

for teste in range(repeticoesQuant):
    valor= int(input())
    print( checkOddOrEven(valor) )