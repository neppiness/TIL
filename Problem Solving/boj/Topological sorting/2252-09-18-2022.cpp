#include <bits/stdc++.h>
using namespace std;

int n, m;
int u, v;
int id[32002];
vector<int> adj[32002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    id[v]++;
  }
  queue<int> q;
  for(int i = 1; i <= n; i++)
    if(!id[i]) q.push(i);

  while(!q.empty()) {
    int cur = q.front(); q.pop();
    cout << cur << ' ';
    for(int nxt : adj[cur]) {
      if(!id[nxt]) continue;
      if(--id[nxt] == 0) q.push(nxt);
    }
  }
}