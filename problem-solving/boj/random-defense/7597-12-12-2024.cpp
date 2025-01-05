#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  while (s != "#") {
    int wa = 0, wb = 0;
    int a = 0, b = 0;
    for (char c : s) {
      a += (c == 'A');
      b += (c == 'B');
      if (a >= 4 && a - b >= 2) {
        wa++;
        a = 0;
        b = 0;
      } else if (b >= 4 && b - a >= 2) {
        wb++;
        a = 0;
        b = 0;
      }
    }
    cout << "A " << wa << ' ' << "B " << wb << '\n';
    cin >> s;
  }
}
