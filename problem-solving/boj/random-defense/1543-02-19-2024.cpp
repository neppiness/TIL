#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s, t;
  getline(cin, s);
  getline(cin, t);
  
  int cnt = 0, pos = 0;
  while (pos < s.size()) {
    int nxt = s.find(t, pos);
    if (nxt == -1) break;
    cnt++;
    pos = nxt + t.size();
  }
  cout << cnt;
}
