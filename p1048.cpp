#include<iostream>
#include<vector>
using namespace std;

int main() {
    int T, M;
    cin >> T >> M;
    vector<int> dp(T + 1);
    dp[0] = 0;

    int ti, pi;
    for (int i = 1; i <= M; i++) {
        cin >> ti >> pi;

        for (int j = T; j >= ti; j--) 
            dp[j] = max(dp[j], dp[j - ti] + pi);
    }

    cout << dp[T] << endl;
    return 0;
}
