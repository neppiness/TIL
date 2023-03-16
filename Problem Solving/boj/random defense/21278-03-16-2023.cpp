#include <bits/stdc++.h>
using namespace std;

const int MX = 100;

int n, m, ans = 0x7f7f7f7f;
vector<int> ans_no;
vector<bool> comb;
// 1-indexed
int d[2][MX + 2], min_d[MX + 2];
vector<int> adj[MX + 2];

void bfs(int st, int i) {
  queue<pair<int, int>> q;
  d[i][st] = 0; min_d[st] = 0;
  q.push({st, i});

  while(!q.empty()) {
    auto [cur, i] = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(d[i][nxt] != -1) continue;
      d[i][nxt] = d[i][cur] + 1;
      min_d[nxt] = min(min_d[nxt], d[i][nxt]);
      q.push({nxt, i});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // combination setup
  comb.resize(n);
  comb[0] = 1;
  comb[1] = 1;

  do {
    memset(d, -1, sizeof(d));
    memset(min_d, 0x7f, sizeof(min_d));

    vector<int> tmpno(2, 0);

    int cnt = 0;
    for(int i = 0; i < n; i++) {
      if(!comb[i]) continue;
      tmpno[cnt++] = i + 1;
    }

    for(int i = 0; i < 2; i++)
      bfs(tmpno[i], i);

    int sum = 0;
    for(int i = 1; i <= n; i++)
      sum += 2*min_d[i];
    
    if(ans <= sum) continue;
    ans = sum;
    ans_no = tmpno;
  } while(prev_permutation(comb.begin(), comb.end()));

  cout << ans_no[0] << ' ' << ans_no[1] << ' ' << ans;
}