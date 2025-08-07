#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int tim(string a) {
    string h = "", m = "";
    int i = 0;
    while (a[i] != ':') h += a[i++];
    i++;
    while (i < a.size()) m += a[i++];

    int hh = 0, mm = 0;
    for (int i = 0; i < h.size(); i++) 
        hh = hh * 10 + (h[i] - '0');

    for (int i = 0; i < m.size(); i++)
        mm = mm * 10 + (m[i] - '0');

    return hh * 60 + mm;
}

int main() {
    string t1, t2;
    int T, n;

    cin >> t1 >> t2;

    int T1 = tim(t1), T2 = tim(t2);

    if (T2 < T1) 
        T = 24 * 60 - T1 + T2;
    else 
        T = T2 - T1;

    cin >> n;
    vector<int> dp(T + 1, 0);


    for (int i = 0; i < n; i++) {
        int ti, ci, pi;
        cin >> ti >> ci >> pi;

        if (pi == 0) {
            for (int j = ti; j <= T; j++) 
                dp[j] = max(dp[j], dp[j - ti] + ci);
        } else {
            for (int j = T; j >= ti; j--) {
                for (int k = 0; k <= pi && k * ti <= j; k++) {
                    dp[j] = max(dp[j], dp[j - k * ti] + ci * k);
                }
            }
        }
    }
    cout << dp[T] << endl;
    return 0;
}

