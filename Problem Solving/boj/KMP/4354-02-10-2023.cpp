#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;

string s;
int f[MX + 2];

int try_match(int len) {
  int j = 0, cnt = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] != s[j]) return 0;
    j++;
    if(j == len) { j = 0; cnt++; }
  }
  return cnt;
}

int solve(int len) {
  int ans = 1;
  while(1) {
    len = f[len - 1];
    if(len == 0) break;
    if(s.size() % len != 0) continue;
    int no_of_match = try_match(len);
    ans = max(ans, no_of_match);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  while(s[0] != '.') {
    int j = 0;
    for(int i = 1; i < s.size(); i++) {
      while(j > 0 && s[i] != s[j]) j = f[j - 1];
      if(s[i] == s[j]) f[i] = ++j;
    }
    int n = solve(s.size());
    cout << n << '\n';
    cin >> s;
  }
}