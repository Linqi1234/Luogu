#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 5000;

struct apple {
    int x, y;
} k[MAXN];

bool cmp(apple m, apple n) {
    return m.y < n.y;
}
int main() {
    int n, s;
    cin >> n >> s;
    int a, b;
    cin >> a >> b;

    for (int i = 0; i < n; i++) {
        cin >> k[i].x >> k[i].y;
        if (k[i].x > a + b) {
            k[i].y = 1001;
        }
    }

    sort(k, k + n, cmp);

    int i = 0, left = s;
    while (i < n && left >= k[i].y) {
          left -= k[i].y;
          i++;
    }
    cout << i << endl;
    return 0;
}
