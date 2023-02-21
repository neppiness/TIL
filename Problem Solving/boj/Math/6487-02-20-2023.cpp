#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct vec {
  double x, y;
  explicit vec(double x_, double y_): x(x_), y(y_) {}

  double cross(vec &r) { return x * r.y - y * r.x; }

  bool operator < (vec &r) { return (x != r.x ? x < r.x : y < r.y); }
  vec operator - (vec r) { return vec(x - r.x, y - r.y); }
  vec operator + (vec r) { return vec(x + r.x, y + r.y); }
  vec operator * (double f) { return vec(f * x, f * y); }
};

void solve() {
  double x1, y1, x2, y2;

  cin >> x1 >> y1 >> x2 >> y2;
  vec a(x1, y1), b(x2 - x1, y2 - y1);

  cin >> x1 >> y1 >> x2 >> y2;
  vec c(x1, y1), d(x2 - x1, y2 - y1);

  double b_cross_d = b.cross(d);
  vec c_minus_a = c - a;
  if(fabs(b_cross_d) < EPS) {
    double c_minus_a_cross_b = c_minus_a.cross(b);
    if(fabs(c_minus_a_cross_b) < EPS) cout << "LINE" << '\n';
    else cout << "NONE" << '\n';
  } else {
    double p = (c_minus_a).cross(d) / b_cross_d;
    vec ans = a + b * p;
    cout << "POINT " << ans.x << ' ' << ans.y << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(2);
  cout << fixed;
  
  int t; cin >> t;
  while(t--) solve();
}