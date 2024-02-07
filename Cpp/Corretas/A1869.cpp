#include <iostream>
#include <string>

using namespace std;

string decimalToBase32(unsigned long long decimal) {
    if (decimal == 0) {
        return "0";
    }

    string base32;
    while (decimal > 0) {
        char digit;
        int memory = decimal % 32;

        if (memory < 10) {
            digit = '0' + memory;
        } else {
            digit = 'A' + (memory - 10);
        }

        base32 = digit + base32;
        decimal /= 32;
    }

    return base32;
}

int main() {
    unsigned long long N;

    while (cin >> N) {
        string base32 = decimalToBase32(N);
        cout << base32 << endl;
        if(N==0){
            break;
        }
    }

    return 0;
}
