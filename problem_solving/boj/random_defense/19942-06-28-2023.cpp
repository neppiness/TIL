#include <bits/stdc++.h>
using namespace std;

set<vector<int>> ans;

int n, mp, mf, ms, mv;
int p[17], f[17], s[17], v[17], c[17];

void solve(int to_pick, int start, int stat) {
  if (!to_pick) {
    int tp = 0, tf = 0, ts = 0, tv = 0, tc = 0;
    for (int e = 0; e < 15; e++) {
      int ex = (1 << e);
      if (ex & stat) {
        tp += p[e]; tf += f[e]; ts += s[e];
        tv += v[e]; tc += c[e];
      }
    }
    if (mp > tp || mf > tf || ms > ts || mv > tv) return;
    vector<int> ans_stat;
    ans_stat.push_back(tc);
    for (int i = 1; i <= n; i++) {
      int ex = (1 << (i - 1));
      if (stat & ex) ans_stat.push_back(i);
    }
    ans.insert(ans_stat);
    return;
  }

  for (int e = start; e < n; e++) {
    int ex = (1 << e);
    solve(to_pick - 1, e + 1, stat | ex);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> mp >> mf >> ms >> mv;
  for (int i = 0; i < n; i++)
    cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];

  for (int to_pick = 1; to_pick <= n; to_pick++)
    solve(to_pick, 0, 0);

  if (ans.size() == 0) {
    cout << -1; return 0;
  }

  vector<int> a = *(ans.begin());
  cout << a[0] << '\n';
  for (int i = 1; i < a.size(); i++) cout << a[i] << ' ';
}