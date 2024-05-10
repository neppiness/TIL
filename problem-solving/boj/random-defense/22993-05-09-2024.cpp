#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin >> n;
  ll jw; cin >> jw;
  for (ll i = 1; i < n; i++) {
    ll x; cin >> x;
    pq.push(x);
  }

  while (!pq.empty()) {
    ll x = pq.top(); pq.pop();
    if (jw <= x) {
      cout << "No";
      return 0;
    }
    jw += x;
  }
  cout << "Yes";
}

