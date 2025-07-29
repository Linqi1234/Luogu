// n <= 1000;

#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1000;
int a[MAXN], arr[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        arr[i] = abs(a[i] - a[i + 1]);
    }

    sort(arr, arr + n - 1);

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] - arr[i - 1] != 1) {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}

