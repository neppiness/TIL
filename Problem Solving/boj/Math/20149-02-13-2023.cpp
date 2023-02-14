#include <bits/stdc++.h>
using namespace std;

struct vec {
  double x, y;
  explicit vec(double x_ = 0, double y_ = 0): x(x_), y(y_) {}

  bool operator < (const vec &r) { return (x != r.x ? x < r.x : y < r.y ); }
  vec operator - (const vec &r) { return vec(x - r.x, y - r.y); }
  double cross(const vec &r) { return (x * r.y - y * r.x); }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << fixed;
  cout.precision(9);
  int right;
}