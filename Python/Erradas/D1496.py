def calcularUltra(picosRegistrados):
    ultras = []
    for index in range(1, len(picosRegistrados)-1):
        ladoEsquerdo = abs(int(picosRegistrados[index]) - int(picosRegistrados[index - 1]))
        ladoDireito=  abs(int(picosRegistrados[index + 1]) - int(picosRegistrados[index]))
        
        if ladoEsquerdo + ladoDireito >= 150000:

            ultras.append(str(index + 1))

    return ultras

quantRegistrada = int(input())
picosRegistrados = input().strip().split(' ')
ultrasEncontrados = calcularUltra(picosRegistrados)
print(' '.join(ultrasEncontrados))