#include <bits/stdc++.h>
using namespace std;

int cx[4], cy[4];

struct vector2 {
  double x, y;
  explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
  double cross(const vector2& rhs) { return (x * rhs.y - y * rhs.x); }
  vector2 operator - (const vector2& rhs) { return vector2(x - rhs.x, y - rhs.y); }
};

double ccw(vector2 ab, vector2 bc) {  return ab.cross(bc); }
double ccw(vector2& a, vector2& b, vector2& c) { return ccw(b - a, c - b); }

bool dtm(vector2& a, vector2& b, vector2& c, vector2& d) {
  bool dtmab = (ccw(c, b, a) * ccw(d, b, a) < 0);
  bool dtmcd = (ccw(a, c, d) * ccw(b, c, d) < 0);
  return dtmab && dtmcd;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 4; i++)  
    cin >> cx[i] >> cy[i];

  vector2 a(cx[0], cy[0]);
  vector2 b(cx[1], cy[1]);
  vector2 c(cx[2], cy[2]);
  vector2 d(cx[3], cy[3]);

  cout << dtm(a, b, c, d) << '\n';

  cout << typeid(a.x).name() << ' ' << typeid(a.y).name();
}