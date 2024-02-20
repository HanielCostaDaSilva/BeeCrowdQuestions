#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Aluno {
    string nome;
    string regiao;
    int custo;

    // Sobrecarga do operador < para ordenação
    bool operator<(const Aluno& outro) const {
        if (custo != outro.custo) {
            return custo < outro.custo;  
        } else if (regiao != outro.regiao) {
            return regiao < outro.regiao;  
        } else {
            return nome < outro.nome; 
        }
    }
};

int main() {
    int Q;
    while (cin >> Q) {

        // preenchendo um vector de alunos
        vector<Aluno> alunos;

        for (int i = 0; i < Q; i++) {
            Aluno aluno;
            cin >> aluno.nome >> aluno.regiao >> aluno.custo;
            alunos.push_back(aluno);
        }

        sort(alunos.begin(), alunos.end());

        for (const auto& aluno : alunos) {
            cout << aluno.nome <<  endl;
        }
    }

    return 0;
}
