#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

const int INF = INT_MAX;

int shortestTime(Graph& graph, int S, int T) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[S] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, S});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return (dist[T] == INF) ? -1 : dist[T];
}

int main() {
    int N;
    cin >> N;

    for (int caseNum = 1; caseNum <= N; ++caseNum) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;

        Graph graph(n);

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        int shortest = shortestTime(graph, S, T);
        if (shortest == -1)
            cout << "Case #" << caseNum << ": unreachable\n";
        else
            cout << "Case #" << caseNum << ": " << shortest << "\n";
    }

    return 0;
}
