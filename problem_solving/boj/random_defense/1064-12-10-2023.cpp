#include <bits/stdc++.h>
using namespace std;

bool is_solved;
int x[4], y[4];
double mn = 40'000, mx = 0;

void solve(int a, int b, int c, int d) {
  int xab = x[b] - x[a];
  int yab = y[b] - y[a];
  int xac = x[c] - x[a];
  int yac = y[c] - y[a];

  if (xab * yac - yab * xac == 0) return;
  x[d] = x[c] + xab;
  y[d] = y[c] + yab;
  int xbd = x[d] - x[b];
  int ybd = y[d] - y[b];
  int xcd = x[d] - x[c];
  int ycd = y[d] - y[c];

  is_solved = 1;
  double ans = 0;
  ans += sqrt(xab * xab + yab * yab);
  ans += sqrt(xac * xac + yac * yac);
  ans += sqrt(xbd * xbd + ybd * ybd);
  ans += sqrt(xcd * xcd + ycd * ycd);
  mn = min(mn, ans);
  mx = max(mx, ans);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(10);
  cout << fixed;

  for (int i = 0; i < 3; i++)
    cin >> x[i] >> y[i];
  
  for (int i = 0; i < 3; i++)
    solve(i, (i + 1) % 3, (i + 2) % 3, 3);

  if (is_solved) cout << mx - mn;
  else cout << "-1.0";
}
