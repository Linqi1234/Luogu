#include<iostream>
using namespace std;
const int MAXN = 14;
int n, a[MAXN], b1[MAXN * 2], b2[MAXN * 2], c[MAXN * 2];
int ans = 0;

void dfs(int x) {
    if (x > n) {
        ans++;
        if (ans <= 3) {
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << endl;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (c[i] == 0 && b1[x + i] == 0 && b2[x - i + MAXN] == 0) {
            a[x] = i;
            c[i] = 1;
            b1[x + i] = 1;
            b2[x - i + MAXN] = 1;

            dfs(x + 1);

            c[i] = 0;
            b1[x + i] = 0;
            b2[x - i + MAXN] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}
