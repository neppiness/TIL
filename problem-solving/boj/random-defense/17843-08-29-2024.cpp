#include <bits/stdc++.h>
using namespace std;

const double A = 1.0 / 120;
const double B = 1.0 / 10;
const double C = 6.0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << fixed;
  cout.precision(9);

  int t; cin >> t;
  while (t--) {
    int h, m, s;
    cin >> h >> m >> s;
    int tot_sec = m * 60 + s;
    double ha = h * 30 + tot_sec * A;
    double hb = tot_sec * B;
    double hc = s * C;

    double ac = abs(ha - hc);
    ac = min(ac, 360 - ac);
    double ab = abs(ha - hb);
    ab = min(ab, 360 - ab);
    double bc = abs(hb - hc);
    bc = min(bc, 360 - bc);
    
    double ans = min(ac, ab);
    ans = min(ans, bc);
    cout << ans << '\n';
  }
}
