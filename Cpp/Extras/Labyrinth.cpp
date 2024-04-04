#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int dx[] = {-1, 0, 1, 0}; // Movimentos em x para cima, direita, baixo e esquerda
const int dy[] = {0, 1, 0, -1}; // Movimentos em y para cima, direita, baixo e esquerda
const char steps[] = {'U', 'R', 'D', 'L'}; // Representação dos movimentos

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    pair<int, int> start, end;
    vector<string> grid(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> prevstep(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                start = {i, j};
            } else if (grid[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = u.first + dx[k];
            int ny = u.second + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                prevstep[nx][ny] = k;
                q.push({nx, ny});
            }
        }
    }

    if (visited[end.first][end.second]) {
        cout << "YES" << endl;
        vector<char> path;
        while (end != start) {
            int p = prevstep[end.first][end.second];
            path.push_back(steps[p]);
            end = {end.first - dx[p], end.second - dy[p]};
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (char c : path) {
            cout << c;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
