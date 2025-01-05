#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    ll x; cin >> x;
    pq.push(x);
  }
  ll ans = 0;
  while (pq.size() > 1) {
    ll x = pq.top(); pq.pop();
    ll y = pq.top(); pq.pop();
    ans += x * y;
    pq.push(x + y);
  }
  cout << ans;
}
