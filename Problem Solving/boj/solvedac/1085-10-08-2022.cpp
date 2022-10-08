#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, y, w, h;
  cin >> x >> y >> w >> h;
  int ans1 = min(w - x, x);
  int ans2 = min(h - y, y);
  cout << min(ans1, ans2);
}