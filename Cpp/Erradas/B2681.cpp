#include <iostream>
#include <string>

using namespace std;

string addLeadingZero(int value) {
    if (value < 10) {
        return "0" + to_string(value);
    }
    return to_string(value);
}

int fastPow(int b, int n) {
    if (n == 0) {
        return 1;
    }

    int res = fastPow(b, n / 2);
    res = (res * res) % (24 * 60);  // Adicione parênteses aqui

    if (n % 2 == 1) {
        res = (res * b) % (24 * 60);  // E aqui
    }

    return res;
}

int main() {
    // Entrada
    string numDiscs;
    cin >> numDiscs;

    // Calcular e imprimir o resultado
    int n = numDiscs.size();
    int totalTime = fastPow(2, n) - 1;
    totalTime %= 24 * 60 * 60;

    int hours = totalTime / 3600;
    int minutes = (totalTime % 3600) / 60;
    int seconds = totalTime % 60;

    // Formatar a saída
    cout << addLeadingZero(hours) << ":" << addLeadingZero(minutes) << ":" << addLeadingZero(seconds) << endl;

    return 0;
}
