#include <bits/stdc++.h>
using namespace std;

const double PI = acos(0.0) * 2;

struct circ {
  double x, y, r;
  explicit circ(double x_ = 0, double y_ = 0, double r_ = 0): x(x_), y(y_), r(r_) {}

  bool operator <(circ &rs) { return r < rs.r; }

  double dist(circ &rs) { return hypot(x - rs.x, y - rs.y); }
  bool conc(circ &rs) { return (x == rs.x) && (y == rs.y); }
  double area() { return (r*r*PI); }
} c[2];

double ar(circ &ci) {
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(3);
  cout << fixed;

  for(int i = 0; i < 2; i++) {
    double x, y, r;
    cin >> x >> y >> r;
    tie(c[i].x, c[i].y, c[i].r) = {x, y, r};
  }
  // 반지름이 작은 원이 c[0], 큰 원이 c[1]이 됨.
  if(c[1] < c[0]) swap(c[1], c[0]);

  double d = c[0].dist(c[1]);
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
  cout << ar(c[0]) + ar(c[1]);
}