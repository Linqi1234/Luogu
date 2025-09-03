#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int N, M;

bool P(int x, const vector<int>& a) {
    int i = 0, cnt = 0;
    while (i < N) {
        if (cnt > M) return 0;
        int sum = 0;
        while (sum + a[i] <= x && cnt < M && i < N) {
            sum += a[i++];
        }
        cnt++;
    }
    return 1;
}

int main() {
    cin >> N >> M;
    vector<int> a(N);
    int sum = 0, max = 1e9;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (sum >= 1e9) {
            sum = 1e9;
            continue;
        }
        sum += a[i];
    }
    int l = 0, r = sum, ans = 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
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
