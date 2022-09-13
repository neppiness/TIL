#include <bits/stdc++.h>
using namespace std;

int n, m;
int u, v;
int ans;

vector<int> adj[1002];
bool vis[1002];
queue<int> q;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1; i <= n; i++) {
    if(vis[i]) continue;
    ans++;
    q.push(i);
    vis[i] = 1;

    while(!q.empty()) {
      int cur = q.front(); q.pop();
      for(auto vtx : adj[cur]) {
        if(vis[vtx]) continue;
        vis[vtx] = 1;
        q.push(vtx);
      }
    }
  }
  cout << ans;
}