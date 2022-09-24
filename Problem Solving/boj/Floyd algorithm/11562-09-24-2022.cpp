#include <bits/stdc++.h>
using namespace std;

const int INF = 987987987;

int n, m, u, v;
bool b;

int d[252][252];
int nxt[252][252];
bool con[252][252];

int solve(int a, int b){
  int cnt = 0, curr = a;
  while(curr != b) {
    int next = nxt[curr][b];
    cnt += con[curr][next];
    swap(next, curr);
  }
  return (d[a][b] - cnt);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    fill(d[i] + 1, d[i] + n + 1, INF);
    d[i][i] = 0;
  }
  
  while(m--){
    cin >> u >> v >> b;
    d[u][v] = 1; d[v][u] = 1;
    con[u][v] = 1; con[v][u] = 1;
    nxt[u][v] = v; nxt[v][u] = u;
    if(!b) con[v][u] = 0;
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++) {
        int tmp = d[i][k] + d[k][j];
        if(tmp < d[i][j]) {
          d[i][j] = tmp;
          nxt[i][j] = nxt[i][k];
        }
      }

  cin >> m;
  while(m--){
    cin >> u >> v;
    cout << solve(u, v) << '\n';
  }
}