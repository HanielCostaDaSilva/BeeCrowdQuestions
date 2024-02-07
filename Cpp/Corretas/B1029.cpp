#include <iostream>

using namespace std;

pair<int, int> fib_rec(int n, int &chamadas)
{
    chamadas++; 

    if (n == 0)
        return pair<int, int>(0, 1);
    else if (n == 1)
        return pair<int, int>(1, 1);

    pair<int, int> result1 = fib_rec(n - 1, chamadas);
    pair<int, int> result2 = fib_rec(n - 2, chamadas);

    return pair<int, int>(result1.first + result2.first, chamadas);
}

pair<int, int> fib(int n)
{
    int chamadas = 0;
    return fib_rec(n, chamadas);
}

int main()
{
    int casosTestes, n;
    cin >> casosTestes;

    for (int i = 0; i < casosTestes; i++)
    {
        cin >> n;
        pair<int, int> result_calls = fib(n);

        cout << "fib(" << n << ") = " << result_calls.second -1 << " calls = " << result_calls.first << endl;
    }

    return 0;
}
