#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  getline(cin, s);
  
  for (char &c : s) {
    if (c >= 'a' && c <= 'z') {
      c -= 13;
      if (c < 'a') {
        c += ('z' - 'a' + 1);
      }
    } else if (c >= 'A' && c <= 'Z') {
      c -= 13;
      if (c < 'A') {
        c += ('Z' - 'A' + 1);
      }
    }
  }
  cout << s;
}
