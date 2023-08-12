#include <bits/stdc++.h>
using namespace std;

int lev;
int b[502][502], memo[502][502];

void solve() {
  for(int i = 1; i < lev; i++) {
    for(int j = 0; j <= i; j++) {
      int& d = memo[i - 1][j];
      memo[i][j] = max(b[i][j] + d, memo[i][j]);
      memo[i][j + 1] = max(b[i][j + 1] + d, memo[i][j + 1]);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> lev;
  for(int i = 0; i < lev; i++)
    for(int j = 0; j <= i; j++)
      cin >> b[i][j];
  
  memo[0][0] = b[0][0];
  solve();

  int mx = 0;
  for(int i = 0; i < lev; i++)
    for(int j = 0; j <= i; j++)
      mx = max(memo[i][j], mx);
  cout << mx;
}