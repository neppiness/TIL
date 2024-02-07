#include <bits/stdc++.h>
using namespace std;

int n, ans; 
int tmp[2], seg[2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> seg[0] >> seg[1];
  while (--n) {
    cin >> tmp[0] >> tmp[1];
    if (seg[0] <= tmp[0] && tmp[0] <= seg[1]) {
      seg[1] = max(seg[1], tmp[1]);
    } else {
      ans += seg[1] - seg[0];
      seg[0] = tmp[0];
      seg[1] = tmp[1];
    }
  }
  ans += seg[1] - seg[0];
  cout << ans;
}