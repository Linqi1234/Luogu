#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100;

struct student {
    string name;
    int year, month, date;
} a[MAXN];

int cmp(student a, student b) {
    if (a.year != b.year) return a.year > b.year;
    if (a.month != b.month) return a.month > b.month;
    return a.date > b.date;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].name >> a[i].year >> a[i].month >> a[i].date;

    stable_sort(a, a + n, cmp);

    for (int i = n - 1; i >= 0; i--) 
        cout << a[i].name << endl;
    return 0;
}
