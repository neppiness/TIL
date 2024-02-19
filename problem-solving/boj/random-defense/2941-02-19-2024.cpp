#include <bits/stdc++.h>
using namespace std;

const string ca[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int cur = 0, cnt = 0;
  while (cur < s.size()) {
    int i = 0;
    bool is_found = 0;
    for (; i < 8; i++) {
      int pos = s.find(ca[i], cur);
      if (pos != cur) continue;
      is_found = 1;
      break;
    }
    if (is_found) {
      cur += ca[i].size();
    } else {
      cur++;
    }
    cnt++;
  }
  cout << cnt;
}
