#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 987987987;

int d[8];
bool fix[8]; // fixed nodes
vector<pair<int,int>> adj[8];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(m--){
    int u, v, c; cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  fill(d, d + n + 1, INF);
  
  int ci = 1, cnt = 0; // ci: current idx
  fix[ci] = 1, d[ci] = 0;
  while(cnt < n - 1) {
    int tmin = INF; // temp. min. value
    for(auto cur : adj[ci])
      d[cur.X] = min(d[cur.X], d[ci] + cur.Y);
    for(int i = 1; i <= n; i++)
      if(!fix[i] && tmin > d[i]) {
        tmin = d[i];
        ci = i;
      }
    fix[ci] = 1;
    cnt++;
  }
  for(int i = 1; i <= n; i++) cout << d[i] << ' ';
}

/*
input:
6 8
1 2 3
1 3 2
1 4 5
2 3 2
2 5 8
3 4 2
4 5 6
5 6 1
*/