#include <bits/stdc++.h>
using namespace std;

int W, H, X, Y, P, R;

bool is_in_rect(int x, int y) {
  if (x < X || x > X + W) return 0;
  if (y < Y || y > Y + H) return 0;
  return 1;
}

bool is_in_cir1(int x, int y) {
  int CX = X;
  int CY = Y + R;
  return R * R >= (x - CX) * (x - CX) + (y - CY) * (y - CY);
}

bool is_in_cir2(int x, int y) {
  int CX = X + W;
  int CY = Y + R;
  return R * R >= (x - CX) * (x - CX) + (y - CY) * (y - CY);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> W >> H >> X >> Y >> P;
  R = H/2;
  int ans = 0;
  while (P--) {
    int x, y; cin >> x >> y;
    ans += is_in_rect(x, y) || is_in_cir1(x, y) || is_in_cir2(x, y);
  }
  cout << ans;
}
