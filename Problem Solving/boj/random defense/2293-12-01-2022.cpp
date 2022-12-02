#include <bits/stdc++.h>
using namespace std;

vector<int> coin;
int dp[10002];
int sum[10002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;

  while(n--) {
    int x; cin >> x;
    coin.push_back(x);
  }

  for(int i = 0; i < coin.size(); i++) {
    int c = coin[i];
    if(c > k) continue;
    dp[c] = 1;
    for(int j = c + 1; j <= k; j++)
      dp[j] = dp[j - c] + sum[j - c];
    for(int j = 1; j <= k; j++)
      sum[j] += dp[j];
    fill(dp, dp + k + 1, 0);
  }
  cout << sum[k];
}