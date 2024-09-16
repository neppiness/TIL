#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j * j <= i; j++)
      ans += (i % j == 0);
  cout << ans;
}
