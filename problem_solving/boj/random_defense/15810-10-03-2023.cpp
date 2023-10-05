#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1'111'111'111'111;

int n, m;
int a[1'000'002];

bool solve(ll cur) {
  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans += cur / a[i];
  return ans >= m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll st = 0, en = INF;
  while (st < en) {
    ll mid = (st + en) / 2;
    if (solve(mid)) en = mid;
    else st = mid + 1;
  }
  cout << st;
}
