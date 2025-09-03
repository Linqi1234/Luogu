#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int L, N, K;

bool P(int x, const vector<int>& a) {
    int last = 0, cnt = K;
    for (int i = 1; i < N; i++) {
        if (a[i] - last <= x) {
            last = a[i];
            continue;
        }
        if (!cnt) return 0;
        if (a[i] - last > x) {
            int num = (a[i] - last) / x;
            if ((a[i] - last) % x == 0) {
                num--;
            }
            if (num <= cnt) {
                cnt -= num;
                last = a[i];
            } else {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    cin >> L >> N >> K;
    vector<int> a(N + 1);
    for (int i = 0; i < N; i++) 
        cin >> a[i];

    int l = 1, r = L, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (P(mid, a)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
