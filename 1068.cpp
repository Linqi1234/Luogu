#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 5000;

struct staff {
    int id, score;
} a[MAXN];

int cmp(staff a, staff b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}

int main() {
    int n, m;
    cin >> n >> m;
    int cnt = m * 1.5;

    for (int i = 0; i < n; i++) {
        cin >> a[i].id >> a[i].score;
    }

    sort(a, a + n, cmp);

    int num = cnt;
    for (int i = cnt; i < n; i++) {
       if (a[i].score == a[i - 1].score)
           num++;
       else break;
    }

    cout << a[cnt - 1].score << " " << num << endl;
    
    for (int i = 0; i < num; i++) 
        cout << a[i].id << " " << a[i].score << endl;
    return 0;
}
