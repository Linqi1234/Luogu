#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1010;
string f[MAXN];

string add(string a, string b) {
    string ans = "";
    int carry = 0;
    int x = a.size() - 1, y = b.size() - 1;

    while (x >= 0 || y >= 0 || carry > 0) {
        int i = x >= 0 ? a[x--] - '0' : 0;
        int j = y >= 0 ? b[y--] - '0' : 0;
        int sum = i + j + carry;
        ans += sum % 10 + '0'; 
        carry = sum / 10;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    f[0] = "1", f[1] = "1";

    for (int i = 2; i <= n - m; i++) {
        f[i] = add(f[i - 1], f[i - 2]); 
    }

    cout << f[n - m] << endl;
    return 0;
}
