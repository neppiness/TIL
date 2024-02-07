#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;

struct line {
  double a, b, c;
  explicit line(double a_ = 0, double b_ = 0, double c_ = 0): a(a_), b(b_), c(c_) {}
  double dist(double x, double y) { return abs(a*x + b*y + c) / hypot(a, b); }
} line;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(3);
  cout << fixed;

  double a, b, c, d, r1, r2;
  cin >> a >> b >> r1 >> c >> d >> r2;


  // 교차하는 경우에만 적용 가능.
  line.a = (2*a - 2*c);
  line.b = (2*b - 2*d);
  line.c = (-a*a - b*b + c*c + d*d + r1*r1 - r2*r2);

  double cd = hypot(a - c, b - d);
  double d1 = line.dist(a, b);
  double d2 = line.dist(c, d);

  if(d2 > d1) {
    swap(a, c); swap(b, d);
    swap(r1, r2); swap(d1, d2);
  }

  // d2 > d1이라면 d1이 더 길도록 몽땅 스왑
  // cd > d1 && cd > d2 조건으로 접근
  // 위 조건이 성립 안 될 시, 
}