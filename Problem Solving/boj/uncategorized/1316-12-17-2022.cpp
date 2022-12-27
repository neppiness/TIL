#include <bits/stdc++.h>
using namespace std;

bool solve() {
  string s; cin >> s;

  bool isused[26] = {};
  isused[s[0] - 'a'] = 1;
  for(int i = 1; i < s.length(); i++) {
    if(isused[s[i] - 'a'])
      if(s[i] != s[i - 1])
        return false;
    isused[s[i] - 'a'] = 1;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int cnt = 0;
  while(n--) cnt += solve();
  cout << cnt;
}