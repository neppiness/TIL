#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[102][102];
int nxt[102][102];

const int INF = 987987987;

void solve(int i, int j){
  int cur = i;
  if(c[i][j] == 0 || c[i][j] == INF) {
    cout << 0 << '\n';
    return;
  }
  queue<int> q;
  while(cur != j) {
    q.push(cur);
    cur = nxt[cur][j];
  }
  q.push(j);

  cout << q.size() << ' ';
  while(!q.empty()){
    cout << q.front() << ' ';
    q.pop();
  }
  cout << '\n';
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    fill(c[i] + 1, c[i] + n + 1, INF);
    c[i][i] = 0;
  }

  int x, y, cost;
  while(m--) {
    cin >> x >> y >> cost;
    if(c[x][y] > cost) {
      c[x][y] = cost;
      nxt[x][y] = y;
    }
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++) {
        int tmp = c[i][k] + c[k][j];
        if(tmp < c[i][j]) {
          c[i][j] = tmp;
          nxt[i][j] = nxt[i][k];
        }
      }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(c[i][j] == INF) cout << 0 << ' ';
      else cout << c[i][j] << ' ';
    }
    cout << '\n';
  }

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) solve(i, j);
}