#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 30000;
int p[MAXN];

int main() {
    int w, n;
    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);

    int i = 0, j = n - 1, ans = 0;

    while (i <= j) {
        if (i == j) {
            ans++;
            break;
        }
        if (p[i] + p[j] <= w) {
            i++;
        } 
        ans++;
        j--;
    }
    cout << ans << endl;
    return 0;
}
