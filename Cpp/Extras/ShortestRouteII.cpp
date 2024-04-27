#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll num_test_cases = 1; 
    while (num_test_cases--) {
        ll num_vertices, num_edges, num_queries;
        cin >> num_vertices >> num_edges >> num_queries; // Entrada do número de vértices, arestas e consultas

        vector<vector<pair<ll, ll>>> adjacency_list(num_vertices + 1);
        vector<vector<ll>> shortest_distances(num_vertices + 1, vector<ll>(num_vertices + 1, LLONG_MAX));

        // Leitura das arestas e seus pesos
        while (num_edges--) {
            ll u, v, w;
            cin >> u >> v >> w;
            // Atualização da matriz de distâncias mínimas
            shortest_distances[u][v] = min(shortest_distances[u][v], w);
            shortest_distances[v][u] = min(shortest_distances[v][u], w);
        }

        // Definição das distâncias mínimas para o mesmo vértice como 0
        for (ll i = 1; i <= num_vertices; i++)
            shortest_distances[i][i] = 0;

        // Algoritmo de Floyd-Warshall para encontrar as menores distâncias entre todos os pares de vértices
        for (ll k = 1; k <= num_vertices; k++) {
            for (ll i = 1; i <= num_vertices; i++) {
                for (ll j = 1; j <= num_vertices; j++) {
                    if ((shortest_distances[i][k] != LLONG_MAX) && (shortest_distances[k][j] != LLONG_MAX))
                        shortest_distances[i][j] = min(shortest_distances[i][j], shortest_distances[i][k] + shortest_distances[k][j]);
                }
            }
        }

        // Processamento das consultas
        while (num_queries--) {
            ll start, end;
            cin >> start >> end;
            cout << ((shortest_distances[start][end] == LLONG_MAX) ? -1 : shortest_distances[start][end]) << endl;
        }
    }
    return 0;
}
