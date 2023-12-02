#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int anguloVerificar;

    while (cin >> anguloVerificar) {
        bool encontrou = false;
        
            if (anguloVerificar %6 == 0) {
                encontrou = true;
            }

        cout << (encontrou ? 'Y' : 'N') << endl;
    }

    return 0;
}
