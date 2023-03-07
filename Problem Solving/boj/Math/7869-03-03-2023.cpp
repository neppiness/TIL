#include <bits/stdc++.h>
using namespace std;

double a, d, e;

struct circ {
  double x, y, r;
  explicit circ(double x_ = 0, double y_ = 0, double r_ = 0): x(x_), y(y_), r(r_) {}

  bool operator <(circ &rs) { return r < rs.r; }

  double dist(circ &rs) { return hypot(x - rs.x, y - rs.y); }
  bool conc(circ &rs) { return (x == rs.x) && (y == rs.y); }
  double area() { return (r * r * M_PI); }
} c[2];

double ar(circ &ci) {
  double alpha = acos((2 * ci.r * ci.r - e*e) / (2 * ci.r * ci.r));
  return ci.r * ci.r * alpha / 2.0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(3);
  cout << fixed;

  for(int i = 0; i < 2; i++) {
    double x, y, r;
    cin >> x >> y >> r;
    circ ci(x, y, r);
    c[i] = ci;
  }
  // 반지름이 작은 원이 c[0], 큰 원이 c[1]이 됨.
  if(c[1] < c[0]) swap(c[1], c[0]);

  d = c[0].dist(c[1]);
  // Case i. 동심원의 경우 작은 원의 넓이 출력
  if(c[0].conc(c[1]) || (d + c[0].r <= c[1].r)) {
    cout << c[0].area();
    return 0;
  }
  // Case ii. 외접원 또는 원의 중심 간 거리가
  // 두 원의 반지름 보다 멀어서 교차하는 영역이 없는 경우
  if(c[0].r + c[1].r <= d) {
    cout << (double)0;
    return 0;
  }
  // Case iii. 두 교점이 만들어지는 경우
  double s = (c[0].r + c[1].r + d) / 2.0;
  a = sqrt(s * (s - c[0].r) * (s - c[1].r) * (s - d));
  a *= 2.0;
  e = 2*a / d;

  double int_sec = ar(c[0]) + ar(c[1]) - a;
  cout << int_sec;
}