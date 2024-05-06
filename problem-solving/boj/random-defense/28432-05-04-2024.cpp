#include <bits/stdc++.h>
using namespace std;

string a[102];
unordered_map<string, bool> w;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int idx = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i].size() == 1) {
      idx = i;
      continue;
    }
    w[a[i]] = 1;
  }

  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    string s; cin >> s;
    if (m == 1) cout << s;
    if (w[s]) continue;
    if (idx == 0) {
      string t = a[1];
      if (s[s.size() - 1] != t[0]) continue;
      cout << s;
    } else if (idx == n - 1) {
      string t = a[n - 2];
      if (s[0] != t[t.size() - 1]) continue;
      cout << s;
    } else {
      string t = a[idx - 1];
      if (s[0] != t[t.size() - 1]) continue;
      t = a[idx + 1];
      if (s[s.size() - 1] != t[0]) continue;
      cout << s;
    }
  }
}
