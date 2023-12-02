    
def descriptografar(mensagemCriptografada:str):
    descriptografou=False
    
    mensagemCriptografada= list(mensagemCriptografada)
    
    for i in range(len(mensagemCriptografada)):
        if mensagemCriptografada[i]==" ":
            continue   
        elif not descriptografou:
            mensagemCriptografada[i]=""
            descriptografou=True
                
        else:
            descriptografou=False
    
    return "".join(mensagemCriptografada)
        
mensagem=descriptografar(input())

print(mensagem)