#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int b, c, d;
  cin >> b >> c >> d;

  vector<int> bb, cc, dd;
  int tot = 0;
  while (b--) {
    int x; cin >> x;
    tot += x;
    bb.push_back(x);
  }
  while (c--) {
    int x; cin >> x;
    tot += x;
    cc.push_back(x);
  }
  while (d--) {
    int x; cin >> x;
    tot += x;
    dd.push_back(x);
  }

  sort(bb.begin(), bb.end(), greater<int>());
  sort(cc.begin(), cc.end(), greater<int>());
  sort(dd.begin(), dd.end(), greater<int>());

  int mx = min(bb.size(), min(cc.size(), dd.size()));
  cout << tot << '\n';
  for (int i = 0; i < mx; i++) {
    tot -= (bb[i] + cc[i] + dd[i]) / 10;
  }
  cout << tot;
}
