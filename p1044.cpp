#include<iostream>
using namespace std;

const int MAXN = 20;
int f[MAXN];

int main() {
    int n;
    cin >> n;

    f[0] = 1, f[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            f[i] += f[j] * f[i - 1 - j];
        }
    }
    
    cout << f[n] << endl;
    return 0;
}
