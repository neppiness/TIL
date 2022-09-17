#include <bits/stdc++.h>
using namespace std;

int n, m;
int u, v;

vector<int> adj[100002];
int p[100002];

int ccnt, tcnt;

void tr(int cur) {
  for(int nxt : adj[cur]) {
    if(p[cur] == nxt) continue;
    else if(p[nxt]) {
      ccnt += (p[nxt] > 0);
      continue;
    }
    p[nxt] = cur;
    tr(nxt);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(m--) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  for(int i = 1; i <= n; i++) {
    if(p[i]) continue;
    tcnt++;
    p[i] = -1;
    tr(i);
  }
  cout << (ccnt + tcnt - 1);
}