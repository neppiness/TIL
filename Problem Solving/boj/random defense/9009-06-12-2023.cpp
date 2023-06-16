#include <bits/stdc++.h>
using namespace std;

int p[46]; // 45번째 피보나치 수 1'134'903'170

int pi(int n) {
  int &ret = p[n];
  if (ret != -1) return ret;
  return ret = pi(n - 1) + pi(n - 2);
}

bool solve(int cur, int st) {
  if (st < 0) return 0;
  if (cur == 0) return 1;

  for (int i = st; i >= 0; i--) {
    int x = pi(i);
    if (cur - x < 0) continue;
    if (solve(cur - x, i - 1)) {
      cout << x << ' ';
      return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));
  p[0] = 0; p[1] = 1; 

  int t; cin >> t;
  while (t--) {
    int x; cin >> x;
    solve(x, 45);
    cout << '\n';
  }
}