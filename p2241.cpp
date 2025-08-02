#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long squ = 0, rec = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = min(n - i, m - j);
            squ += tmp;
            rec += (n - i) * (m - j) - tmp;
        }
    }
    cout << squ << ' ' << rec << endl;
    return 0;
}
