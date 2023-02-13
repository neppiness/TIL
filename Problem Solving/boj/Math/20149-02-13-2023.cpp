#include <bits/stdc++.h>
using namespace std;

struct vec {
  double x, y;
  explicit vec(double x_ = 0, double y_ = 0): x(x_), y(y_) {}

  bool operator < (const vec &rhs) { return (x != rhs.x ? x < rhs.x : y < rhs.y ); }
  vec operator - (const vec &rhs) { return vec(x - rhs.x, y - rhs.y); }
  double cross(const vec &rhs) { return (x * rhs.y - y * rhs.x); }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << fixed;
  cout.precision(9);
  
}