class No:
    def __init__(self, carga: any):
        self.carga = carga
        self.esq = None
        self.dir = None

    def __str__(self):
        return f' carga: {str(self.carga)}'

    def __eq__(self, no: 'No'):
        return self.carga == no.carga

# == == == ==Classe que contém todos os métodos a árvore binária


class ArvoreBusca:
    # == == == Método que cria a raiz
    def __init__(self, carga_da_raiz=None):
        self.__raiz = No(
            carga_da_raiz) if carga_da_raiz != None else carga_da_raiz

    @property
    def raiz(self):
        return self.__raiz

    # == == == Método que confere se a raiz está vazia
    def estaVazia(self) -> bool:
        if self.__raiz == None:
            return True
        else:
            return False

    def criarRaiz(self, valor_raiz: any) -> any:

        self.__raiz = No(valor_raiz)

    def adicionar(self, carga: any) -> None:
        if self.__raiz is not None:
            self.__adicionar(carga, self.__raiz)
        else:
            self.criarRaiz(carga)

    def __adicionar(self, cargaAdicionar: any, no: 'No'):

        if cargaAdicionar < no.carga:
            if no.esq is None:
                no.esq = No(cargaAdicionar)
            else:
                self.__adicionar(cargaAdicionar, no.esq)

        elif cargaAdicionar > no.carga:

            if no.dir is None:
                no.dir = No(cargaAdicionar)

            else:
                self.__adicionar(cargaAdicionar, no.dir)

    def prefixo(self):
 
        valoresPosicionados = []
        self.__prefixo(self.__raiz, valoresPosicionados)
        return valoresPosicionados

    def __prefixo(self, no: No, listaValores: list):

        if no is not None:
            listaValores.append(str(no.carga))
            self.__prefixo(no.esq, listaValores)
            self.__prefixo(no.dir, listaValores)

    def infixo(self):
   
        valoresPosicionados = []
        self.__infixo(self.__raiz, valoresPosicionados)
        return valoresPosicionados

    def __infixo(self, no: No, listaValores: list):
   
        if no is not None:
            self.__infixo(no.esq, listaValores)
            listaValores.append(str(no.carga))
            self.__infixo(no.dir, listaValores)

    def posfixo(self):
   
        valoresPosicionados = []
        self.__posfixo(self.__raiz, valoresPosicionados)
        return valoresPosicionados

    def __posfixo(self, no: No, listaValores: list):
   
        if no is not None:
            self.__posfixo(no.esq, listaValores)
            self.__posfixo(no.dir, listaValores)
            listaValores.append(str(no.carga))

    def busca(self, key) -> bool:
        if self.__raiz is None:
            return False
        else:
            return self.__busca(key, self.__raiz)

    def __busca(self, valorProcurado, nodeAtual: No) -> bool:

        if nodeAtual is None:
            return False

        elif nodeAtual.carga == valorProcurado:
            return True

        else:
            if valorProcurado < nodeAtual.carga:
                return self.__busca(valorProcurado, nodeAtual.esq)

            elif valorProcurado > nodeAtual.carga:
                return self.__busca(valorProcurado, nodeAtual.dir)
            
    
    def remover(self, chave):
        self.__remover(chave, self.__raiz)

    def __remover(self, chave, no):
        if no is None:
            return no

        if chave < no.carga:
            no.esq = self.__remover(chave, no.esq)
        
        elif chave > no.carga:
            no.dir = self.__remover(chave, no.dir)
        
        else:
            if no.esq is None:
                return no.dir
            elif no.dir is None:
                return no.esq

            temp = self.min_valor(no.dir)

            no.carga = temp.carga

            no.dir = self.__remover(temp.carga, no.dir)

        return no

    def min_valor(self, no):
        atual = no
        while atual.esq is not None:
            atual = atual.esq
        return atual

arvore = ArvoreBusca()

while True:
    try:
        comando = input().split()
        if comando[0] == "I":
            arvore.adicionar(int(comando[1]))

        elif comando[0] == "INFIXA":
            print(" ".join(arvore.infixo()))

        elif comando[0] == "PREFIXA":

            print(" ".join(arvore.prefixo()))

        elif comando[0] == "POSFIXA":
            print(" ".join(arvore.posfixo()))

        elif comando[0] == "P":
            resultado = f"{int(comando[1])} existe" if arvore.busca(int(comando[1])) else f"{int(comando[1])} nao existe"
            print(resultado)
        
        elif comando[0] == "R":
            arvore.remover(int(comando[1]))
    
    except EOFError:
        break
