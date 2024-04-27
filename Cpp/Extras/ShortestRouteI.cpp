#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
typedef long double ld;


#define INF LLONG_MAX // Valor infinito para representar distâncias inalcançáveis

// Função para encontrar o caminho mais curto utilizando o algoritmo de Dijkstra
void dijkstra(int64 start, vector<vector<pair<int64, int64>>> &adjacency_list, vector<int64> &shortest_distances) {
    priority_queue<pair<int64, int64>, vector<pair<int64, int64>>, greater<pair<int64, int64>>> pq;
    pq.push({0, start}); // Inserindo o nó inicial com distância 0 na fila

    // Loop principal do algoritmo de Dijkstra
    while (!pq.empty()) {
        int64 current_distance = pq.top().first; 
        int64 node = pq.top().second; 
        pq.pop(); // Remove o nó da fila

        // Se a distância atual for maior que a menor distância conhecida para este nó, ignoramos
        if (current_distance > shortest_distances[node])
            continue;

        // Percorre todos os vizinhos do nó atual
        for (auto &neighbor : adjacency_list[node]) {
            int64 next_node = neighbor.first; // Próximo nó a ser explorado
            int64 weight = neighbor.second; // Peso da aresta entre o nó atual e o próximo nó

            // Se o caminho passando por este vizinho é mais curto do que o conhecido anteriormente, atualizamos a distância e adicionamos o vizinho à fila de prioridade
            if (shortest_distances[next_node] > current_distance + weight) {
                shortest_distances[next_node] = current_distance + weight;
                pq.push({shortest_distances[next_node], next_node});
            }
        }
    }
}

int main() {

    int64 num_cities, num_connections;
    cin >> num_cities >> num_connections; 

    // Vetor de adjacência para armazenar os vizinhos de cada cidade e o peso das arestas
    vector<vector<pair<int64, int64>>> adjacency_list(num_cities + 1);
    // Vetor para armazenar as distâncias mais curtas a partir do nó de partida (1)
    vector<int64> shortest_distances(num_cities + 1, INF);
    shortest_distances[1] = 0; // A distância para o nó de partida é 0

    for (int64 i = 0; i < num_connections; i++) {
        int64 city1, city2, distance;
        cin >> city1 >> city2 >> distance;
        adjacency_list[city1].push_back({city2, distance});
    }

    dijkstra(1, adjacency_list, shortest_distances);

    for (int64 i = 1; i <= num_cities; i++)
        cout << shortest_distances[i] << " ";

    return 0;
}
