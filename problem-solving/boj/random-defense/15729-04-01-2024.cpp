#include <bits/stdc++.h>
using namespace std;

bool a[1'000'002], b[1'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) continue;
    for (int j = 0; j < 3; j++)
      b[i + j] = !b[i + j];
    ans++;
  }
  cout << ans;
}
