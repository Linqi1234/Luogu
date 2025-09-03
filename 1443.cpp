#include <cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int MAXN = 4001;
int n, m, x, y, step[MAXN][MAXN];
struct Node {
    int xi, yi, dist;
};

int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};

void bfs() {
    queue<Node> q;
    q.push({x, y, 0});
    step[x][y] = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cur.xi + dx[i];
            int ny = cur.yi + dy[i];
            
            if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
                if (step[nx][ny] == -1) {
                    step[nx][ny] = cur.dist + 1;
                    q.push({nx, ny, cur.dist + 1});
                } 
            }
        }
    }

}

int main() {
    cin >> n >> m >> x >> y;
    memset(step, -1, sizeof(step));
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << step[i][j] << " ";
        cout << endl;
    }
    return 0;
}
