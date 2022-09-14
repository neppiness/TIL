#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;
vector<int> fr[10002];
int cnt[10002];

int bfs() {
  queue<int> q;
  cnt[1] = 0;
  q.push(1);
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int f : fr[cur]) {
      if(cnt[f] != -1) continue;
      cnt[f] = cnt[cur] + 1;
      if(cnt[f] <= 2) ans++;
      q.push(f);
    }
  }
  return ans;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int u, v;
  while(m--) {
    cin >> u >> v;
    fr[u].push_back(v);
    fr[v].push_back(u);
  }

  fill(cnt, cnt + 10002, -1);
  cout << bfs();
}