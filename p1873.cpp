#include<iostream>
#include<algorithm>
using namespace std;
int a[1000000], n, m;

bool check(int x) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= x) 
            sum += a[i] - x;
    }
    return sum >= m;
}

int main() {
    cin >> n >> m;
    int maxlen = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxlen = max(maxlen, a[i]);
    }
    int l = 0, r = maxlen;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << r - 1 << endl;
}
