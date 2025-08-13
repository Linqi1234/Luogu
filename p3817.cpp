#include<iostream>
using namespace std;
int a[100000];

int main() {
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    int cur = a[0];
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] + cur > x) {
            ans += a[i] + cur - x;
            cur = max(0, x - cur);
        } else {
            cur = a[i];
        }
        cout << cur << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
