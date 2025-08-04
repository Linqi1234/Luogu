#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string add(string a, string b) {
    string res;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int x = i >= 0 ? a[i--] - '0' : 0;
        int y = j >= 0 ? b[j--] - '0' : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        res += (sum % 10 + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> f(n + 1);
    f[0] = "1";
    f[1] = "1";

    for (int i = 2; i <= n; i++) {
        f[i] = add(f[i - 1], f[i - 2]);
    }

    cout << f[n ] << endl;
    return 0;
}
