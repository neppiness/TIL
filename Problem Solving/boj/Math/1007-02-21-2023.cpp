#include <bits/stdc++.h>
using namespace std;

const int MX = 20 + 2;

int n;
bool is_used[MX];
double ans;

struct vec {
  double x, y;
  explicit vec(double x_ = 0, double y_ = 0): x(x_), y(y_) {}

  vec operator - (vec &r) { return vec(x - r.x, y - r.y); }
  bool operator < (vec &r) { return (x != r.x ? x < r.x : y < r.y); }
  double norm() { return hypot(x, y); }
};

vector<vec> vecs;

void solve() {
  ans = 10e+9;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> vecs[i].x >> vecs[i].y;
  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++) {
      vec ij = vecs[j] - vecs[i];
      double l = ij.norm();
      ans = min(ans, l);
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(9);
  cout << fixed;

  int t; cin >> t;
  while(t--) {
    solve();
    cout << ans << '\n';
  }
}