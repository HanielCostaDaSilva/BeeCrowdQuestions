# Calculador de tempo de evento
# formato hh : mm : ss
# Na terceira e quarta linha de entrada haverá outra informação no mesmo formato das duas primeiras linhas, indicando o término do evento.

def calcularTempo(diaInicial, tempoInicial, diaFinal, tempoFinal):
    diaInicial = int(diaInicial.split()[-1])  
    diaFinal = int(diaFinal.split()[-1]) 
    tempoInicial = list(map(int, tempoInicial))
    tempoFinal = list(map(int, tempoFinal))

    resultado = [0, 0, 0, 0]  # dia, hora, minuto, segundo

    # Cálculo dos segundos
    if tempoFinal[2] >= tempoInicial[2]:
        resultado[3] = tempoFinal[2] - tempoInicial[2]
    else:
        resultado[3] = 60 + tempoFinal[2] - tempoInicial[2]
        tempoFinal[1] -= 1

    # Cálculo dos minutos
    if tempoFinal[1] >= tempoInicial[1]:
        resultado[2] = tempoFinal[1] - tempoInicial[1]
    else:
        resultado[2] = 60 + tempoFinal[1] - tempoInicial[1]
        tempoFinal[0] -= 1

    # Cálculo das horas
    if tempoFinal[0] >= tempoInicial[0]:
        resultado[1] = tempoFinal[0] - tempoInicial[0]
    else:
        resultado[1] = 24 + tempoFinal[0] - tempoInicial[0]
        diaFinal -= 1

    # Cálculo dos dias
    resultado[0] = diaFinal - diaInicial

    return resultado

diaInicio = input()
tempoInicio = input().split(" : ")
diaEncerramento = input()
tempoEncerramento = input().strip().split(" : ")

dias, horas, minutos, segundos = calcularTempo(
    diaInicio, tempoInicio, diaEncerramento, tempoEncerramento)
print(f"{dias} dia(s)\n{horas} hora(s)\n{minutos} minuto(s)\n{segundos} segundo(s)")
