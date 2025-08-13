#include<iostream>
#include<algorithm>
using namespace std;

struct contest {
    int l, r;
} con[1000000];

bool cmp(const contest& a, const contest& b) {
    return a.r < b.r;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> con[i].l >> con[i].r;

    sort(con, con + n, cmp);

    int start = con[0].l, end = con[0].r;
    int ans = 1;

    for (int i = 1; i < n; i++) {
        if (con[i].l >= end) {
            start = con[i].l;
            end = con[i].r;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

