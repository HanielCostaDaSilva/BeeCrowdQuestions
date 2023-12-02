#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> ledsNumeroQuantidade = {
        {'0', 6},
        {'1', 2},
        {'2', 5},
        {'3', 5},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 3},
        {'8', 7},
        {'9', 6}};

    string numerosLed;
    int flag;
    cin >> flag;

    for (int i = 0; i < flag; i++)
    {
        cin >> numerosLed;
        int quantLeds = 0;

        for (char numero : numerosLed)
        {
            quantLeds += ledsNumeroQuantidade[numero];
        }

        cout << quantLeds << " leds" << endl;
    }
    return 0;
}
