#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN = 305;
int h[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h, h + n);

    int l = 0, r = n - 1;
    long long ans = h[n - 1] * h[n - 1];
    while (l < r) {
        if (l < r) {
            ans += pow((h[r] - h[l]), 2);
            r--;
        }
        if (l < r) {
            ans += pow((h[r] - h[l]), 2);
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}
