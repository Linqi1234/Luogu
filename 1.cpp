#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char x, y;
    int z;
    cin >> x >> y >> z;

    if (x == 'A') {
        if (y == 'N') {
            cout << 'A320' << endl;
        } else {
            if (z == 2) cout << 'A350' << endl;
            else cout << 'A380' << endl;
        }
    } else if (x == 'B') {
        if (y == 'N') {
            cout << 'B737' << endl;
        } else {
            if (z == 2) cout << 'B787' << endl;
            else cout << 'B747' << endl;
        }
    } else if (x == 'C') {
        cout << 'C919' << endl;
    }
    return 0;
}
