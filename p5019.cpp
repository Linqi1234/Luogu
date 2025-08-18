#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0, prev = 0;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > prev) {
            ans += x - prev;
        }
        prev = x;
    }

    cout << ans << endl;
    return 0;
}
