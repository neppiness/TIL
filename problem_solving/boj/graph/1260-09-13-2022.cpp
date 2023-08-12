#include <bits/stdc++.h>
using namespace std;

int n, m, v;
vector<int> adj[1002];
queue<int> q;
stack<int> st;
bool vis[1002];

void dfs(){
  st.push(v);
  while(!st.empty()) {
    int cur = st.top(); st.pop();
    if(vis[cur]) continue;
    vis[cur] = 1;
    cout << cur << ' ';
    for(auto it = adj[cur].rbegin(); it != adj[cur].rend(); it++)
      st.push(*it);
  }
  cout << '\n';
}

void bfs() {
  fill(vis, vis+1002, 0);
  q.push(v);
  vis[v] = 1;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    cout << cur << ' ';
    for(int vtx : adj[cur]) {
      if(vis[vtx]) continue;
      vis[vtx] = 1;
      q.push(vtx);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> v;

  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v); 
    adj[v].push_back(u);
  }

  for(int i = 1; i <= n; i++)
    if(!adj[i].empty()) sort(adj[i].begin(), adj[i].end());

  dfs();
  bfs();
}