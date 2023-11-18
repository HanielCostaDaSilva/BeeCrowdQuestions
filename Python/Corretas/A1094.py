# Maria acabou de iniciar seu curso de graduação na faculdade de medicina e precisa de sua ajuda para organizar os experimentos de um laboratório o qual ela é responsável. Ela quer saber no final do ano, quantas cobaias foram utilizadas no laboratório e o percentual de cada tipo de cobaia utilizada.

# Este laboratório em especial utiliza três tipos de cobaias: sapos, ratos e coelhos. Para obter estas informações, ela sabe exatamente o número de experimentos que foram realizados, o tipo de cobaia utilizada e a quantidade de cobaias utilizadas em cada experimento.

# sapos, ratos e coelhos.


experimentos = int(input())

cobaiasPorExperimento = {
    "C": 0,
    "R": 0,
    "S": 0
}

cobaiasTotal = 0

for experimento in range(experimentos):

    quantidadeCobaia, cobaiaSigla = input().strip().split()

    cobaiasPorExperimento[cobaiaSigla] = cobaiasPorExperimento[cobaiaSigla] + \
        int(quantidadeCobaia)

    cobaiasTotal += int(quantidadeCobaia)


percentualCoelhos = (cobaiasPorExperimento['C'] / cobaiasTotal) * 100
percentualRatos = (cobaiasPorExperimento['R'] / cobaiasTotal) * 100
percentualSapos = (cobaiasPorExperimento['S'] / cobaiasTotal) * 100

print(f"""Total: {cobaiasTotal} cobaias
Total de coelhos: {cobaiasPorExperimento['C']}
Total de ratos: {cobaiasPorExperimento['R']}
Total de sapos: {cobaiasPorExperimento['S']}
Percentual de coelhos: {percentualCoelhos:.2f} %
Percentual de ratos: {percentualRatos:.2f} %
Percentual de sapos: {percentualSapos:.2f} %""")
