#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;

  while(n--) {
    int x; cin >> x;
    pq.push(x);
  }

  while(m--) {
    ll sum = pq.top(); pq.pop();
    sum += pq.top(); pq.pop();
    pq.push(sum); pq.push(sum);
  }

  ll ans = 0;
  while(!pq.empty()) {
    ans += pq.top(); pq.pop();
  }
  cout << ans;
}