dias= int(input())

anos = dias // 365
dias-= anos*365
meses = dias // 30
dias -= meses * 30

print(f"{anos} ano(s)\n{meses} mes(es)\n{dias} dia(s)")