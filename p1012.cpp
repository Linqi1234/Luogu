#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int MAXN = 20;
string a[MAXN];

int cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cin >> a[0];
        cout << a[0] << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) 
        cin >> a[i];

    sort(a, a + n, cmp);

    string ans = a[0];

    for (int i = 1; i < n; i++) {
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}
