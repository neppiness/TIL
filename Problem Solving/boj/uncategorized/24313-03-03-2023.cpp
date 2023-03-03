#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a1, a0, c, n0;
  cin >> a1>> a0 >> c >> n0;

  int cr = c - a1;
  if(cr > 0) {
    cout << (a0 <= cr*n0);
  } else if(cr == 0) {
    // a0가 0보다 작거나 같은 정수인 경우 성립
    cout << (a0 <= 0);
  } else {
    // n이 무한히 커지기 때문에 성립 불가.
    cout << 0;
  }
}