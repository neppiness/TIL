#include <bits/stdc++.h>
using namespace std;

bool a[200'002];
int ans = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    int x, y; cin >> x >> y;
    ans += (a[x] == y);
    a[x] = y;
  }
  for (int i = 1; i <= 200'000; i++)
    ans += a[i];
  cout << ans;
}
