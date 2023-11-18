dicionarioPalavras = {}
novaLista = []

while True:
    try:
        linha = input()
        palavras = linha.lower().split()
        
        for palavra in palavras:
            subpalavras = palavra.split()
            
            for subpalavra in subpalavras:
                subpalavraFormatada = ''.join(caracter for caracter in subpalavra if caracter.isalpha())
                
                if subpalavraFormatada:
                    dicionarioPalavras[subpalavraFormatada] = dicionarioPalavras.get(subpalavraFormatada, 0) + 1
                    novaLista.append(subpalavraFormatada)
    except:
        break

palavrasOrdenadas = sorted(set(novaLista))

for palavra in palavrasOrdenadas:
    print(palavra)
