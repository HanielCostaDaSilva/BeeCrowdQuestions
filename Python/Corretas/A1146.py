
while True:
    limite= int(input())
    
    if limite == 0:
        break
   
    for i in range(limite):
        valor= i + 1
   
        if valor == limite:
            print(limite)
            break
   
        print(valor, end=' ')