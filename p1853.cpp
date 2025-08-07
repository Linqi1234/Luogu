#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int s, n, d;
    cin >> s >> n >> d;
    int S = s / 1000;
    vector<int> a(d), b(d);
    for (int i = 0; i < d; i++) {
        cin >> a[i] >> b[i];
        a[i] /= 1000;
    }


    vector<int> dp(S + 1, 0);
    while (n--) {
        dp.resize(S + 1, 0); 
        fill(dp.begin(), dp.end(), 0);
        for (int i = 0; i < d; i++) {
            for (int j = a[i]; j <= S; j++) {
                dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
        }
        s += dp[S];
        S = s / 1000;
    }

    cout << s << endl;
    return 0;
}

