#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct vec {
  ll x, y;
  vec(ll x_ = 0, ll y_ = 0): x(x_), y(y_) {}
  ll operator * (vec &rt) {  return x * rt.x + y * rt.y; }
  ll lensq() { return x * x + y * y; }
} v[4];

pair<ll, ll> c[4];

void solve() {
  for (int i = 0; i < 4; i++) {
    ll x, y; cin >> x >> y;
    c[i] = {x, y};
  }

  int p[] = {0, 1, 2, 3};
  bool is_square = 0;
  do {
    // set vectors
    for (int i = 0; i < 4; i++) {
      int j = (i + 1) % 4;
      ll x = c[p[i]].first - c[p[j]].first;
      ll y = c[p[i]].second - c[p[j]].second;
      v[i] = vec(x, y);
    }

    // length comp logic
    bool is_diff_len = 0;
    for (int i = 0; i < 4; i++) {
      int j = (i + 1) % 4;
      if (v[i].lensq() == v[j].lensq()) continue;
      is_diff_len = 1; break;
    }
    if (is_diff_len) continue;

    // orthogonality check
    bool are_rigth_angles = 1;
    for (int i = 0; i < 4; i++) {
      int j = (i + 1) % 4;
      if (v[i] * v[j] == 0) continue;
      are_rigth_angles = 0; break;
    }
    if (!are_rigth_angles) continue;
    is_square = 1;
  } while (next_permutation(p, p + 4));
  cout << is_square << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}