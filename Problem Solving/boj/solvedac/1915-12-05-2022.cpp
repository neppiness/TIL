#include <bits/stdc++.h>
using namespace std;

int b[1002][1002];
int dp[1002][1002];

int n, m;
int mx;

int solve() {
  for(int i = 1; i < n; i++) {
    for(int j = 1; j < m; j++) {
      if(!b[i][j]) {
        dp[i][j] = 0;
        continue;
      }
      int mn = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
      dp[i][j] = b[i][j] + mn;
      mx = max(mx, dp[i][j]);
    }
  }
  return mx;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char a; cin >> a;
      b[i][j] = (int)(a - '0');
      if(b[i][j]) mx = 1;
    }
  }
  
  for(int i = 0; i < n; i++)
    dp[i][0] = b[i][0];

  for(int j = 0; j < m; j++)
    dp[0][j] = b[0][j];

  int len = solve();
  cout << len * len << '\n';
}