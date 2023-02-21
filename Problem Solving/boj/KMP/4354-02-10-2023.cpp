#include <bits/stdc++.h>
using namespace std;

string s;

vector<int> failure(string &s) {
  vector<int> f(s.size());
  int j = 0;
  for(int i = 1; i < s.size(); i++) {
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  return f;
}

int try_match(int len) {
  int j = 0, cnt = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] != s[j]) return 0;
    j++;
    if(j == len) { j = 0; cnt++; }
  }
  return cnt;
}

void solve() {
  vector<int> f = failure(s);
  int ans = 1, len = s.size();
  while(1) {
    len = f[len - 1];
    if(len == 0) break;
    if(s.size() % len != 0) continue;
    int no_of_match = try_match(len);
    ans = max(ans, no_of_match);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  while(s[0] != '.') {
    solve();
    cin >> s;
  }
}