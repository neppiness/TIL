#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  int v1 = x1 - x2;
  int w1 = y1 - y2;
  int v2 = x1 - x3;
  int w2 = y1 - y3;
  
  int calc = v1 * w2 - w1 * v2;
  if (calc) {
    cout << "WINNER WINNER CHICKEN DINNER!";
  } else {
    cout << "WHERE IS MY CHICKEN?";
  }
}
