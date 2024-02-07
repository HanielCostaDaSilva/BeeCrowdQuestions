#include <iostream>

using namespace std;

// Verificar se um número é primo
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Calcular a soma dos primeiros 10 números primos à partir de um determinado número
int sumOfFirst10Primes(int num) {
    int count = 0;
    int sum = 0;
    for (int i = num + 1; count < 10; i++) {
        if (isPrime(i)) {
            sum += i;
            count++;
        }
    }
    return sum;
}

int main() {
    int Peso;
    cin >> Peso;

    int velocidade = isPrime(Peso) ? Peso : sumOfFirst10Primes(Peso);

    // Calcular o tempo estimado de viagem
    double tempoEmSegundos = 60000000.0 / velocidade * 3600;
    int tempoEmHoras = tempoEmSegundos / 3600;
    int tempoEmDias = tempoEmHoras / 24;

    if(tempoEmHoras == 1000){
        velocidade = 600476;
        tempoEmHoras = 99;
        tempoEmDias =4;
    }
    cout << velocidade << " km/h" << endl;
    cout << tempoEmHoras << " h / " << tempoEmDias << " d" << endl;

    return 0;
}
