#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s; cin >> s;
  for (char c : s) {
    int a = c - 3;
    if (a < 'A') {
      a += 'Z' - 'A' + 1;
    }
    cout << (char)a;
  }
}
