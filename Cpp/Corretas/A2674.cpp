#include <iostream>
#include <vector>

using namespace std;

// Verificar se um número é primo
bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string number;

    while (cin >> number)
    {

        if (isPrime(stoi(number)))
        {
            bool isSuper = true;

            for (char n : number)
            {

                int x = stoi(string(1, n));

                if (!isPrime(x))
                {
                    isSuper = false;
                    break;
                }
            }
            if (isSuper)
                cout << "Super" << endl;
            else
                cout << "Primo" << endl;
        }
        else
        {
            cout << "Nada" << endl;
        }
    }

    return 0;
}
