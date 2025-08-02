#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN = 50000;

double s(int x1, int y1, int z1, int x2, int y2, int z2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
}

struct point {
    int x, y, z;
} a[MAXN];

int cmp(point a, point b) {
    return a.z < b.z;
}

int main() {
    double distance = 0.0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a, a + n, cmp);
    for (int i = 1; i < n; i++) {
        double tmp = s(a[i].x, a[i].y, a[i].z, a[i - 1].x, a[i - 1].y, a[i - 1].z);
        distance += tmp;
    }
    cout << fixed << setprecision(3) << distance << endl;
    return 0;
}

