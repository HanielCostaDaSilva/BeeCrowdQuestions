#include <iostream>

using namespace std;

int main()
{
    int c, n, m;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        cin >> n >> m;
        int radares = (n + m - 1) / m;

        cout << radares << endl;
    }

    return 0;
}
