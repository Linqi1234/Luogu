#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define eps 1e-4
double a, b, c, d;

double f(double x) {
    return a * pow(x, 3) + b * x * x + c * x + d;
}
int main() {
    int cnt = 0;
    cin >> a >> b >> c >> d;
    for (int i = -100; i <= 100; i++) {
        double l = i, r = i + 1, mid;
        if (fabs(f(l)) < eps) {
            cout << fixed << setprecision(2) << l << " ";
            cnt ++;
            continue;
        } 
        if (f(l) * f(r) < 0) {
            while (r - l > eps) {
                mid = (l + r) / 2;
                if (f(mid) * f(l) > 0) 
                    l = mid;
                else 
                    r = mid;
            }
            cout << fixed << setprecision(2) << (l + r) / 2 << " ";
            cnt++;
        }
        if (cnt == 3) {
            cout << endl;
            return 0;
        } 
    }
}
