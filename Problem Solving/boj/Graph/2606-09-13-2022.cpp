#include <bits/stdc++.h>
using namespace std;

vector<int> adj[102];
queue<int> q;
bool vis[102];

int cnt;
int n, m;

int bfs(){
  q.push(1);
  vis[1] = 1;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for(int vtx : adj[cur]) {
      if(vis[vtx]) continue;
      vis[vtx] = 1;
      cnt++;
      q.push(vtx);
    }
  }
  return cnt;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cout << bfs();
}