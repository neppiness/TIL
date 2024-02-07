#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
string s;
bool vis[20'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'H') continue;
    for (int j = -k; j <= k; j++) {
      if (i + j < 0 || i + j >= n) continue;
      if (vis[i + j] || s[i + j] == 'P') continue;
      vis[i + j] = 1;
      cnt++; break;
    }
  }
  ans = max(cnt, ans);

  memset(vis, 0, sizeof(vis));
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'H') continue;
    for (int j = k; j >= -k; j--) {
      if (i + j < 0 || i + j >= n) continue;
      if (vis[i + j] || s[i + j] == 'P') continue;
      vis[i + j] = 1;
      cnt++; break;
    }
  }
  cout << max(ans, cnt);
}