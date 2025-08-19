#include<iostream>
#include<algorithm>
using namespace std;

struct milk {
    int p, a;
} arr[5000];

bool cmp(milk x, milk y) {
    return x.p < y.p;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> arr[i].p >> arr[i].a;
    }
    sort(arr, arr + m, cmp);
    int left = n, num = 0, sum = 0;

    while (num < m && left > 0) {
        if (left >= arr[num].a) {
            sum += arr[num].p * arr[num].a;
            left -= arr[num].a;
        } else {
            sum += left * arr[num].p;
            break;
        }
        num++;
    }

    cout << sum << endl;
    return 0;
}
