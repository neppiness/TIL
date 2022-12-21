#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'002;
const int INF = 0x7f7f7f7f;

int ltln[MX]; // use length as an index to get last number of seq.

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(ltln, ltln + MX, INF);

  int n; cin >> n;
  while(n--) {
    int x; cin >> x;
    int len = lower_bound(ltln + 1, ltln + MX, x) - ltln;
    if(ltln[len] < x) ltln[len + 1] = x;
    else ltln[len] = x;
  }
  int ans = lower_bound(ltln + 1, ltln + MX, MX) - ltln - 1;
  cout << ans;
}
