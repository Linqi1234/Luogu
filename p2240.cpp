#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct coin {
    int m, v;
} a[110];

bool cmp(coin a, coin b) {
    return a.v * b.m > b.v * a.m;
}

int main() {
    int n, T;
    cin >> n >> T;

    for (int i = 0; i < n; i++)
        cin >> a[i].m >> a[i].v;

    sort(a, a + n, cmp);
    double sum = 0, ans = 0, rem;

    for (int i = 0; i < n && sum < T; i++) {
        rem = T - sum;
        if (rem >= a[i].m) {
            sum += a[i].m;
            ans += a[i].v;
        } else {
            ans += rem * a[i].v / a[i].m;
            break;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
