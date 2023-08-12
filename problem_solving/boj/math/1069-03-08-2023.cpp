#include <bits/stdc++.h>
using namespace std;

struct vec {
  double x, y;
  explicit vec(double x_ = 0, double y_ = 0): x(x_), y(y_) {}

  vec operator * (const int &n) { return vec(x*n, y*n); }
  vec operator - (vec r) { return vec(x - r.x, y - r.y); }
  double norm() { return hypot(x, y); }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(12);
  cout << fixed;

  int x, y, d, t;
  cin >> x >> y >> d >> t;

  vec ej(x, y);

  // 점프 벡터 선언
  double ejsz = ej.norm();
  vec jump(double(x*d) / ejsz, double(y*d) / ejsz);
  
  double ans = 1.0e+9;
  for(int n = 0; n <= 2000; n++) {
    vec remained = ej - jump*n;
    double tmp = n*t + remained.norm();
    ans = min(ans, tmp);
    if(remained.x < 0 && n >= 2) {
      ans = min(ans, double(n * t));
      break;
    }
  }
  cout << ans;
}