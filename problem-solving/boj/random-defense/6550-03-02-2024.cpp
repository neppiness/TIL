#include <bits/stdc++.h>
using namespace std;

string s, t;

bool solved() {
  int pos = 0;
  for (char c : s) {
    int nxt = t.find(c, pos);
    if (nxt == -1) return 0;
    pos = nxt + 1;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> s) {
    cin >> t;
    if (solved()) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
