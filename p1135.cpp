#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node {
    int floor, d;
};
queue<node> q;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> k(n + 1), vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> k[i];

    q.push((node){a, 0});
    vis[a] = 1;
    node cur;
    while (!q.empty()) {
        cur = q.front();
        if (cur.floor == b) {
            break;
        }
        q.pop();
        int cur_f = cur.floor;
        int fmax = cur_f + k[cur_f], fmin = cur_f - k[cur_f];
        if (fmax <= n && vis[fmax] == 0) {
            q.push((node){fmax, cur.d + 1});
            vis[fmax] = 1;
        }
        if (fmin >= 1 && vis[fmin] == 0) {
            q.push((node){fmin, cur.d + 1});
            vis[fmin] = 1;
        }
    }
    if (cur.floor == b) 
        cout << cur.d << endl;
    else 
        cout << -1 << endl;
    return 0;
}

