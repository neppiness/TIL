#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p[47];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));
  p[0] = 0; p[1] = 1;

  int n; cin >> n;
  for (int i = 2; i <= n; i++)
    p[i] = p[i - 2] + p[i - 1];

  cout << p[n];
}
