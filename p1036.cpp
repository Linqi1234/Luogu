#include<iostream>
using namespace std;
int n, k, ans = 0;
const int N = 25;
int a[N];

bool is_prime(int x) {
    if (x == 2)
        return 1;
    else if (x % 2 == 0 || x == 1)
        return 0;
    else 
        for (int i = 3; i * i <= x; i+= 2) {
        if (x % i == 0)
            return 0;
        }
    return 1;
}

void dfs(int start, int num, int sum) {
    if (num == k) 
        if (is_prime(sum)) 
            ans++;

    for (int i = start; i < n; i++) {
        dfs(i + 1, num + 1, sum + a[i]);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    dfs(0, 0 ,0);
    cout << ans << endl;
    return 0;

}
