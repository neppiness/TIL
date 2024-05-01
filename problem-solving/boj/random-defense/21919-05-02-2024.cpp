#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MILL = 1'000'000;

bool is_pr[MILL + 2];
bool is_used[MILL + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(is_pr, 1, sizeof(is_pr));
  is_pr[0] = 0;
  is_pr[1] = 0;

  for (int i = 2; i <= MILL; i++) {
    if (!is_pr[i]) continue;
    for (ll j = i; i * j <= MILL; j++) {
      is_pr[i * j] = 0;
    }
  }

  int n; cin >> n;
  ll ans = 1;
  while (n--) {
    ll x; cin >> x;
    if (!is_pr[x] || is_used[x]) continue;
    ans *= x;
    is_used[x] = 1;
  }
  if (ans == 1) ans = -1;
  cout << ans;
}
