#include<iostream>
#include<cstring>
using namespace std;
string a;
int n;
char ans;

void spin(string a) {
    int m = a.size();

    if (n <= m) 
        ans = a[n - 1];
    else {
        a += a[m - 1];

        for (int i = 0; i < m - 1; i++)
            a += a[i];
        spin(a);
    }
}


int main() {
    cin >> a;
    cin >> n;
    spin(a);
    cout << ans << endl;
    return 0;
}
