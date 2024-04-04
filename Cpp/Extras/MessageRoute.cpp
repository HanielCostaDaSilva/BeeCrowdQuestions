#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> prevNode;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    prevNode[start] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                prevNode[v] = u;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    prevNode.resize(n + 1, -1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);

    if (!visited[n]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        int node = n;
        while (node != -1) {
            path.push_back(node);
            node = prevNode[node];
        }

        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
