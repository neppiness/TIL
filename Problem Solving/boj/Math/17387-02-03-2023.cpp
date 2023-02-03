#include <bits/stdc++.h>
using namespace std;

struct vector2 {
  double x, y;
  explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

  bool operator < (const vector2& rhs) { return x != rhs.x ? x < rhs.x : y < rhs.y; }
  vector2 operator - (const vector2& rhs) { return vector2(x - rhs.x, y - rhs.y); }

  double cross(const vector2& rhs) { return (x * rhs.y - y * rhs.x); }
};

double ccw(vector2 ab, vector2 bc) { return ab.cross(bc); }
double ccw(vector2& a, vector2& b, vector2& c) { return ccw(b - a, c - b); }

bool meet_check(vector2& a,vector2& b,vector2& c,vector2& d) {
  vector2 ab[2] = {a, b};
  vector2 cd[2] = {c, d};
  sort(ab, ab + 2);
  sort(cd, cd + 2);
  if(ab[0] < cd[0]) {
    return !(ab[1] < cd[0]);
  } else if(cd[0] < ab[0]) {
    return !(cd[1] < ab[0]);
  }
  return 1;
}

bool solve(vector2& a,vector2& b,vector2& c,vector2& d) {
  double ccws[4] = {ccw(a, c, d), ccw(b, c, d), ccw(c, a, b), ccw(d, a, b)};
  double dtm[2] = {ccws[0] * ccws[1], ccws[2] * ccws[3]};
  if(dtm[0] == 0 && dtm[1] == 0)
    return meet_check(a, b, c, d);
  return (dtm[0] <= 0) && (dtm[1] <= 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  vector2 a(x1, y1); vector2 b(x2, y2);

  cin >> x1 >> y1 >> x2 >> y2;
  vector2 c(x1, y1); vector2 d(x2, y2);

  cout << solve(a, b, c, d);
}