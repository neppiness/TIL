#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  ll v1 = x1 - x2;
  ll w1 = y1 - y2;
  ll v2 = x2 - x3;
  ll w2 = y2 - y3;
  ll v3 = x3 - x1;
  ll w3 = y3 - y1;

  ll sq1 = v1*v1 + w1*w1;
  ll sq2 = v2*v2 + w2*w2;
  ll sq3 = v3*v3 + w3*w3;
  ll a[3] = {sq1, sq2, sq3};
  sort(a, a + 3);

  ll cross = v1*w2 - w1*v2;

  if (sq1 == sq2 && sq2 == sq3) {
    cout << "JungTriangle";
    return 0;
  }
  
  if (cross == 0) {
    cout << "X";
    return 0;
  }

  if (a[0] == a[1] || a[1] == a[2]) {
    if (a[2] == a[0] + a[1]) {
      cout << "Jikkak2Triangle";
      return 0;
    } else if (a[2] < a[0] + a[1]) {
      cout << "Yeahkak2Triangle";
      return 0;
    } else {
      cout << "Dunkak2Triangle";
      return 0;
    }
  }

  if (a[2] == a[0] + a[1])
    cout << "JikkakTriangle";
  else if (a[2] < a[0] + a[1])
    cout << "YeahkakTriangle";
  else
    cout << "DunkakTriangle";
}
