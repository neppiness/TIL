#include <bits/stdc++.h>
using namespace std;

int ans[1002];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ans[0] = 1;
  ans[1] = 1;
  ans[2] = 3;

  int n; cin >> n;
  for(int i = 3; i <= n; i++)
    ans[i] = (ans[i-1]*ans[1] + ans[i-2]*(ans[2] - 1)) % 10007;
  
  cout << ans[n];
}