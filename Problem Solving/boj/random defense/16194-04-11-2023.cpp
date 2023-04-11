#include <bits/stdc++.h>
using namespace std;

const int MX = 1002;

int n, p[MX], ans[MX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(ans, 0x7f, sizeof(ans));
  ans[0] = 0;

  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> p[i];

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= i; j++)
      ans[i] = min(ans[i], p[j] + ans[i - j]);
  cout << ans[n];
}