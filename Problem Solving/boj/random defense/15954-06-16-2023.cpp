#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
ll p[502], s[502];
double ans;

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

  ll sumsq = (p[k] - p[0]) * (p[k] - p[0]);
  ll sqsum = (s[k] - s[0]);
  ll eq = k * sqsum - sumsq;
  ans = sqrt(eq); ans /= k;

  double tmp;
  for (int i = k; i <= n; i++) {
    sumsq = (p[i] - p[i - k]) * (p[i] - p[i - k]);
    sqsum = (s[i] - s[i - k]);
    eq = k * sqsum - sumsq;
    tmp = sqrt(eq);
    ans = min(ans, tmp / k);
  }
  cout.precision(11);
  cout << fixed << ans;
}