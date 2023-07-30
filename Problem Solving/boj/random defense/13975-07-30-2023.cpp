#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<ll, vector<ll>, greater<ll>> pq;

void solve() {
  int n; cin >> n;
  while (n--) {
    ll x; cin >> x;
    pq.push(x);
  }
  ll tot = 0;
  while (pq.size() > 1) {
    ll a = pq.top(); pq.pop();
    ll b = pq.top(); pq.pop();
    tot += a + b;
    pq.push(a + b);
  }
  pq.pop();
  cout << tot << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}