#include <iostream>
#include <map>

using namespace std;

int main() {
    int quantidadePresentePorDia = 0;
    int flag;
    map<string, int> horasProduzirBrinquedo = {
        {"bonecos", 8},
        {"arquitetos", 4},
        {"musicos", 6},
        {"desenhistas", 12}
    };
    map<string, int> gruposHorasTrabalhando = {
        {"bonecos", 0},
        {"arquitetos", 0},
        {"musicos", 0},
        {"desenhistas", 0}
    };

    cin >> flag;

    for (int i = 0; i < flag; i++) {
        string _, grupo;
        int horaByDiaTrabElfo;

        cin >> _ >> grupo >> horaByDiaTrabElfo;

        gruposHorasTrabalhando[grupo] += horaByDiaTrabElfo;
    }

    // Calcula a quantidade total de presentes produzidos por dia
    for (const auto& par : gruposHorasTrabalhando) {
        quantidadePresentePorDia += par.second / horasProduzirBrinquedo[par.first];
    }

    cout << quantidadePresentePorDia << endl;

    return 0;
}
