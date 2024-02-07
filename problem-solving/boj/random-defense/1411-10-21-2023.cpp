#include <bits/stdc++.h>
using namespace std;

string s[102];

bool solve(int u, int v) {
  unordered_map<char, char> chk;
  bool is_used[28] = {};
  string s1 = s[u];
  string s2 = s[v];
  for (int i = 0; i < s1.size(); i++) {
    if (chk[s1[i]] == 0) {
      if (is_used[s2[i] - 'a']) return 0;
      is_used[s2[i] - 'a'] = 1;
      chk[s1[i]] = s2[i];
    } else {
      if (chk[s1[i]] != s2[i]) return 0;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];

  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      cnt += solve(i, j);
  cout << cnt;
}
