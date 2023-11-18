#Paulinho tem em suas mãos um novo problema. Agora a sua professora lhe pediu que construísse um programa para verificar, à partir de dois valores muito grandes A e B, se B corresponde aos últimos dígitos de A.

def checaEncaixa(valorA:str, valorB:str):
    
    if valorB == valorA[-(len(valorB)):]: #Checa o final do valorA.
       return "encaixa"    
    else:
       return "nao encaixa"  

testes =int(input())

for teste in range(testes):
    A,B= input().strip().split()
    print( checaEncaixa(A, B) )