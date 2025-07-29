//1 <= N <= 2e4, 1 <= Hi <= 1e4, 1 <= B <= S <= 2e9 + 7;
//O(n), O(n);
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 20000;
int h[MAXN];

int main() {
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++) 
        cin >> h[i];

    sort(h, h + n, greater<int>()); 

    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        sum += h[i];
        cnt++;
        if (sum >= b) break; 
    }
    cout << cnt << endl;
    return 0;
}
