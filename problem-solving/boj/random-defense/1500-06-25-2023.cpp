#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int s, k; cin >> s >> k;
  for (int i = 0; i < k; i++) {
    a[i] = (s / k);
  }

  int rest = s % k;
  for (int i = 0; i < rest; i++)
    a[i]++;

  ll ans = 1;
  for (int i = 0; i < k; i++)
    ans *= a[i];
  cout << ans;
}