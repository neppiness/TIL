#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long f, lim;
  cin >> f >> lim;

  long long ans;
  if (f == 1 || f == 5) {
    ans = lim * 8 + 4 * (f == 5);
  } else {
    ans = (lim / 2) * 8;
    if (lim % 2 == 0) {
      ans += f - 1;
    } else {
      ans += 9 - f;
    }
  }
  cout << ans;
}
