// N <= 10000;
// O(n^2), O(n);

#include<iostream>
using namespace std;

const int MAXN = 10000;
int a[MAXN];

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
