#include <bits/stdc++.h>
using namespace std;

struct seg {
  int a, b;
  explicit seg(int a_ = 0, int b_ = 0): a(a_), b(b_) {}

  int posi(seg &r) {
    if(b < r.a || r.b < a) return 1; // 1. 만나지 않는다.
    if(b == r.a || r.b == a) return 2; // 2. 한 점에서 만난다.
    return 3; // 3. 선분으로 만난다.
  }
} seg_x[2], seg_y[2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 4;
  while(t--) {
    for(int i = 0; i < 2; i++) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      seg_x[i] = seg(a, c);
      seg_y[i] = seg(b, d);
    }

    int x_posi = seg_x[0].posi(seg_x[1]);
    int y_posi = seg_y[0].posi(seg_y[1]);

    if(x_posi == 3 && y_posi == 3) {
      cout << 'a' << '\n'; // a. 직사각형
    } else if(x_posi == 2 && y_posi == 3) {
      cout << 'b' << '\n'; // b. 선분(1)
    } else if(x_posi == 3 && y_posi == 2) {
      cout << 'b' << '\n'; // b. 선분(2)
    } else if(x_posi == 2 && y_posi == 2) {
      cout << 'c' << '\n'; // c. 점
    } else {
      cout << 'd' << '\n'; // d. 공통 부분 없음
    }
  }
}