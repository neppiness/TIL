#include <bits/stdc++.h>
using namespace std;

struct team {
  int id; // team id
  int ts; // total score
  int sc[102]; // score for each problem
  int nt; // number of try
  int ls; // last submit time

  team() {}

  bool operator < (const team &t) {
    if (ts != t.ts) return ts > t.ts;
    if (nt != t.nt) return nt < t.nt;
    return ls < t.ls;
  }

  void reset() {
    ts = 0; nt = 0; ls = 0;
    memset(sc, 0, sizeof(sc));
  }

  void calc(int k) {
    for (int i = 1; i <= k; i++)
      ts += sc[i];
  }
} teams[102];

int solve() {
  int n, k, t, m;
  cin >> n >> k >> t >> m;
  for (int i = 1; i <= n; i++) {
    teams[i].reset();
    teams[i].id = i;
  }

  for (int i = 1; i <= m; i++) {
    int id, no, sc;
    cin >> id >> no >> sc;
    team &t = teams[id];
    t.nt++;
    t.sc[no] = max(t.sc[no], sc);
    t.ls = i;
  }

  for (int i = 1; i <= n; i++) {
    teams[i].calc(k);
  }

  sort(teams + 1, teams + n + 1);
  for (int i = 1; i <= n; i++) {
    if (teams[i].id == t) return i;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;
  while (T--)
    cout << solve() << '\n';
}
