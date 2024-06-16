#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll r[100'002];
ll cnt[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, k, x;
  cin >> n >> m >> k >> x;
  
  r[0] = x;
  for (int i = 1; i <= n; i++) {
    ll d; cin >> d;
    r[i] = r[i - 1] + d;
    cnt[i] = cnt[i - 1] + (r[i] < k);
  }

  while (m--) {
    int st, en; cin >> st >> en;
    cout << cnt[en - 1] - cnt[st - 1] << '\n';
  }
}
