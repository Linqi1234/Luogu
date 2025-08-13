#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[10000];

int main() {
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 2) {
        cout << a[0] + a[1]<< endl;
        return 0;
    }
    sort(a, a + n);
    vector<int> b(n, 0x7f7f7f7f);
    int cost = a[0] + a[1], i = 2, j = 0, w1, w2, n2 = 1;
    b[0] = cost;
    for (int k = 2; k < n; k++) {
        w1 = (i < n && a[i] < b[j]) ? a[i++] : b[j++];
        w2 = (i < n && a[i] < b[j]) ? a[i++] : b[j++];
        b[n2++] = w1 + w2;
        cost += w1 + w2;
    }
    cout << cost << endl;
    return 0;

}
