#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

// Função BFS para encontrar o menor número de cliques necessários para alcançar m a partir de n
long long int bfs(long long int* n, long long int* m) {
    
    queue<pair<long long int, long long int>> q;
    // Inicializa a fila com o nó inicial e o nível 0
    q.push({*n, 0});

    // Conjunto para rastrear os nós visitados
    unordered_set<long long int> visited;

    visited.insert(*n);

    while (!q.empty()) {

        long long int node = q.front().first;
        long long int level = q.front().second;
        // Remove o nó atual da fila
        q.pop();

        // Se o nó atual for igual ao destino, retorna o nível
        if (node == *m) {
            return level;
        }

        // Verifica se é possível multiplicar o nó atual por 2 e o resultado não foi visitado
        if (node * 2 < 10001 && visited.find(node * 2) == visited.end()) {

            q.push({node * 2, level + 1});
            // Marca o novo nó como visitado
            visited.insert(node * 2);
        }

        // Verifica se é possível subtrair 1 do nó atual e o resultado não foi visitado
        if (node - 1 >= 1 && visited.find(node - 1) == visited.end()) {
            // Adiciona o novo nó à fila com nível incrementado
            q.push({node - 1, level + 1});
            // Marca o novo nó como visitado
            visited.insert(node - 1);
        }
    }

    // Retorna -1 se o destino não puder ser alcançado
    return -1;
}

int main() {
    long long int n, m;
    cin >> n >> m;
    cout << bfs(&n, &m) << endl;

    return 0;
}
