#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
int k, q;

int solve() {
  ll a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);

  ll tmpa = a, tmpb = b;
  int fla = 0;
  while (tmpa) {
    tmpa /= k;
    fla++;
  }

  int flb = 0;
  while (tmpb) {
    tmpb /= k;
    flb++;
  }

  int cnt = flb - fla;
  int ans = flb - fla;
  while (cnt--) b /= k;

  while (a != b) {
    a /= k;
    b /= k;
    ans += 2;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> q;
  while (q--) cout << solve() << '\n';
}
