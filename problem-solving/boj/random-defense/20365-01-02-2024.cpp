#include <bits/stdc++.h>
using namespace std;

int n, r, b;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  char prv;
  if (s[0] == 'B') {
    prv = 'B';
    b++;
  } else {
    prv = 'R';
    r++;
  }

  for (int i = 1; i < s.size(); i++) {
    if (s[i] == prv) continue;
    if (s[i] == 'B') {
      prv = 'B';
      b++;
    } else {
      prv = 'R';
      r++;
    }
  }
  cout << min(b, r) + 1;
}
