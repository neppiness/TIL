#include <bits/stdc++.h>
using namespace std;

int n, m;
int cm[502][502];
int nxt[502][502];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++) fill(cm[i] + 1, cm[i] + n + 1, 987987987);
  for(int i = 1; i <= n; i++) cm[i][i] = 0;

  while(m--) {
    int x, y, cost;
    cin >> x >> y >> cost;
    if(cost < cm[x][y]) {
      cm[x][y] = cost;
      nxt[x][y] = y;
    }
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++) {
        int tmp = cm[i][k] + cm[k][j];
        if(tmp < cm[i][j]) {
          cm[i][j] = tmp;
          nxt[i][j] = k;
        }
      }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) cout << cm[i][j] << ' ';
    cout << '\n';
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) cout << nxt[i][j] << ' ';
    cout << '\n';
  }

  for(int i = 1; i <= 1; i++)
    for(int j = 1; j <= n; j++) {
      int cur = i;
      while(cur != j) {
        cout << cur << ' ';
        cur = nxt[cur][j];
      }
      cout << cur << '\n';
    }
}