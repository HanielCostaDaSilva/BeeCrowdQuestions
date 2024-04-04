#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> grid;
int n, m;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#') {
        return;
    }

    grid[x][y] = '#'; 

    // explore neighboring cells
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    cin >> n >> m;

    grid.resize(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int rooms = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                dfs(i, j);
                rooms++;
            }
        }
    }

    cout << rooms << endl;

    return 0;
}
