#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int n, k;
ll p[502], s[502];
ld ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    s[i] = p[i] * p[i];
    p[i] += p[i - 1];
    s[i] += s[i - 1];
  }

  ll sumsq = p[k] * p[k];
  ll sqsum = s[k];
  ll eq = k * sqsum - sumsq;
  ans = sqrt(eq); ans /= k;

  ld tmp;
  for (int j = k; j <= n; j++) {
    for (int i = j; i <= n; i++) {
      sumsq = (p[i] - p[i - j]) * (p[i] - p[i - j]);
      sqsum = (s[i] - s[i - j]);
      eq = j * sqsum - sumsq;
      tmp = sqrt(eq);
      ans = min(ans, tmp / j);
    }
  }
  cout.precision(11);
  cout << fixed << ans;
}