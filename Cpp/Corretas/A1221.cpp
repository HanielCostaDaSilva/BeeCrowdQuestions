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
    for (int i = 2; i *     i <= num; i++)
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
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        if (isPrime(number))
        {
            cout << "Prime" << endl;
        }
        else
        {
            cout << "Not Prime" << endl;
        }
    }

    return 0;
}
