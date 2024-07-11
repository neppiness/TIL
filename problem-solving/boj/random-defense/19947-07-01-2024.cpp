#include <bits/stdc++.h>
using namespace std;

int h, y; 
int a[12];

void solve(int x) {
  for (int d : {1, 3, 5}) {
    int nxt = x + d;
    if (nxt > y) continue;
    switch (d) {
      case 1:
        a[nxt] = max(a[nxt], a[x] * 21 / 20);
        solve(nxt);
        break;
      case 3: 
        a[nxt] = max(a[nxt], a[x] * 6 / 5);
        solve(nxt);
        break;
      default:
        a[nxt] = max(a[nxt], a[x] * 27 / 20);
        solve(nxt);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> h >> y;
  a[0] = h;
  solve(0);
  cout << a[y];
}
