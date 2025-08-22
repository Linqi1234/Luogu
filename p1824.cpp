#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100010;
int n, m, a[MAXN];

bool P(int x) {
    int sum = 1, prev = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] >= prev + x) {
            sum++;
            prev = a[i];
        }
        if (sum == m) return 1;
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int l = 0, r = a[n] - a[1] - m, ans;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (P(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;

}
