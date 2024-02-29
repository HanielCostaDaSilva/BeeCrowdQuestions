#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Armazenar a entrada ordenada em uma estrutura de dados adequada
        vector<pair<int, string>> v;
        for (int i = 0; i < n; ++i) {
            int matricula;
            string classificacao;
            cin >> matricula >> classificacao;
            v.push_back({matricula, classificacao});
        }
        sort(v.begin(), v.end());

        // Calcular a resposta
        int count = 0;
        for (int i = 1; i < n; ++i) {
            if (v[i].second < v[i - 1].second) {
                count += (n - i);
            }
        }

        cout << count << endl;
    }

    return 0;
}