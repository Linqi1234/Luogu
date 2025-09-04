#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 310, INF = 10000;
int ans[MAXN][MAXN], death[MAXN][MAXN];
struct star {
    int x, y;
};
queue<star> q;
int main() {
    int m, xi, yi, ti, t = 0;
    cin >> m;
    fill(&death[0][0], &death[0][0] + MAXN * MAXN, INF);
    memset(ans, -1, sizeof(ans));
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    while (m--) {
        cin >> xi >> yi >> ti;
        death[xi][yi] = min(death[xi][yi], ti);
        for (int i = 0; i < 4; i++) {
            int nx = xi + dx[i], ny = yi + dy[i];
            if (nx >= 0 && ny >= 0) 
                death[nx][ny] = min(death[nx][ny], ti);
        }  
    }
    q.push((star){0, 0});
    ans[0][0] = 0;
    while (!q.empty()) {
        star cur = q.front();
        q.pop();
        int t = ans[cur.x][cur.y];
        if (death[cur.x][cur.y] == INF) {
            cout << t << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int curx = cur.x + dx[i];
            int cury = cur.y + dy[i];
            if (death[curx][cury] > t + 1 && ans[curx][cury] == -1 && curx >= 0 && cury >= 0) {
                q.push((star){curx, cury});
                ans[curx][cury] = ans[cur.x][cur.y] + 1;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
