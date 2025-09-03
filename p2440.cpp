#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, k;


int P(int x, const vector<int>& a) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += a[i] / x;
        if (cnt >= k) return 1;
    }
    return 0;
}

int main() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    sort(a.begin(), a.end());

    int l = 1, r = a[0], ans;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (P(mid, a)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
