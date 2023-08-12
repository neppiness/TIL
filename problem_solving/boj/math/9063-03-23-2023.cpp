#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  int mxx = -10001 , mxy = -10001;
  int mnx = 10001, mny = 10001;

  while(n--) {
    int x, y; cin >> x >> y;
    mxx = max(mxx, x);
    mxy = max(mxy, y);
    mnx = min(mnx, x);
    mny = min(mny, y);
  }
  cout << (mxx - mnx) * (mxy - mny);
}