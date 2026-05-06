#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
char grid[MAX][MAX];
bool visited[MAX][MAX];
int m, n;

// 8 個方向移動 (上, 下, 左, 右, 以及對角線)
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

// DFS 遞迴探索油田
void dfs(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '@' || visited[x][y])
        return;

    visited[x][y] = true; // 標記已訪問

    // 遍歷 8 個方向
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        dfs(nx, ny);
    }
}

int main() {
    while (cin >> m >> n, m && n) {  // 直到輸入 0 0 結束
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        // 初始化 visited 陣列
        memset(visited, false, sizeof(visited));

        int oilCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@' && !visited[i][j]) {
                    dfs(i, j);  // 搜索這個油田
                    oilCount++; // 計數
                }
            }
        }
        cout << oilCount << endl;
    }
    return 0;
}