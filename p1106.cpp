#include<iostream>
#include<cstring>
using namespace std;

int main() {
   string n;
   int k; 
   cin >> n >> k;
   string str;
   int length = n.size();
   str.reserve(length);

   for (int i = 0; i < length; i++) {
       while (k > 0 && !str.empty() && str.back() > n[i]) {
           str.pop_back();
           k--;
       }
       str.push_back(n[i]);
   }

   while (k > 0 && !str.empty()) {
       str.pop_back();
       k--;
   }

   int x = 0;
   while (x < str.size() && str[x] == '0') 
       x++;

   if (x == str.size()) {
       cout << 0 << endl;
   } else {
       cout << str.substr(x) << endl;
   }
   return 0;
}
