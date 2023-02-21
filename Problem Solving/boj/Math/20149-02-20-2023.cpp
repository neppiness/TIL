#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-12;

struct vec {
  double x, y;
  explicit vec(double x_, double y_): x(x_), y(y_) {}
  explicit vec(): x((double)0), y((double)0) {}

  double cross(vec r) { return x * r.y - y * r.x; }

  bool operator < (vec &r) { return (x != r.x ? x < r.x : y < r.y); }
  bool operator == (vec &r) { return (fabs(x - r.x) < EPS && fabs(y - r.y) < EPS); }

  vec operator - (vec r) { return vec(x - r.x, y - r.y); }
  vec operator + (vec r) { return vec(x + r.x, y + r.y); }
  vec operator * (double f) { return vec(f * x, f * y); }
} a, b, c, d;

void print_ans(vec &ans) {
  cout << 1 << '\n';
  cout << ans.x << ' ' << ans.y;
}

void par_chk() {  // 두 방향 벡터가 평행한 경우
  double ac_cross_ab = (c - a).cross(b - a);
  if(fabs(ac_cross_ab) == 0) { // 동일선 상에 있는 경우
    if(b < c || d < a) cout << 0;
    else if(b == c) print_ans(b);
    else if(a == d) print_ans(a);
    else cout << 1;
  } else cout << 0; // 동일선 상에 있지 않은 경우
}

bool in_range(double &cpvalue) {
  return (fabs(cpvalue) >= 0 && fabs(cpvalue) <= 1 + EPS);
}

void non_par_chk() {  // 두 방향 벡터가 평행하지 않은 경우
  vec cd = d - c, ac = c - a, ab = b - a, ad = d - a;
  double p = ac.cross(cd) / ab.cross(cd);
  double q = ac.cross(ab) / ab.cross(cd);
  if(in_range(p) && in_range(q)) {
    vec ans = a + (ab)*p;
    print_ans(ans);
  } else { cout << 0; }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(12);
  cout << fixed;
  
  double x1, y1, x2, y2;

  cin >> x1 >> y1 >> x2 >> y2;
  a = vec(x1, y1), b = vec(x2, y2);

  cin >> x1 >> y1 >> x2 >> y2;
  c = vec(x1, y1), d = vec(x2, y2);

  if(b < a) swap(a, b);
  if(d < c) swap(c, d);

  double ab_cross_cd = (b - a).cross(d - c);
  if(fabs(ab_cross_cd) < EPS) par_chk();
  else non_par_chk();
}