#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int l, n, m;


int f(int x, const vector<int>& a) {
    int cnt = m, dist;
    for (int i = 1; i <= n + 1; i++) {
        dist = a[i] - a[i - 1];
        if (dist >= x) {
            continue;
        }
        if (dist < x) {
            if (i <  n + 1) {
                i++;
            }
            if (a[i] - a[i - 2] < x || !cnt)
                return 0;
            else if (a[i] - a[i - 2] >= x && cnt) {
                cnt--;
            }
        }
    }
    return 1;
}

int main() {
    cin >> l >> n >> m;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans;
    a[n + 1] = l;
    int left = 1, right = l;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (f(mid, a)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
