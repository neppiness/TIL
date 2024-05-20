#include <bits/stdc++.h>
using namespace std;

string s; 

bool solve() {
  int idx = 0;
  while (idx < s.size()) {
    if (s[idx] == 'p') {
      string ss = s.substr(idx, 2);
      if (ss != "pi") return 0;
      idx += 2;
    } else if (s[idx] == 'k') {
      string ss = s.substr(idx, 2);
      if (ss != "ka") return 0;
      idx += 2;
    } else {
      string ss = s.substr(idx, 3);
      if (ss != "chu") return 0;
      idx += 3;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  string pr[] = {"NO", "YES"};
  cout << pr[solve()];
}
