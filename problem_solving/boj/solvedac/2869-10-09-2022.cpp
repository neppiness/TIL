#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, y, v;
  cin >> x >> y >> v;

  int ans = (v - y)/(x - y);
  if((v - y)%(x - y) != 0) ans++;
  cout << ans;
}