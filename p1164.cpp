#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 1010;
int a[MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) 
        cin >> a[i];

    vector<int> dp(m + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
        }
    }

    cout << dp[m] << endl;
    return 0;
}
