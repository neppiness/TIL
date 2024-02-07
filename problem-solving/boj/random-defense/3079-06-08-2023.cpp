#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue < pair<ll, int>,
    vector<pair<ll, int>>,
    greater<pair<ll, int>> > pq;

int n, m;
ll t[100'002], ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> t[i];
  
  for (int i = 0; i < n; i++) {
    if (m == 0) break;
    pq.push({t[i], i});
    m--;
  }

  while (!pq.empty()) {
    auto [time, id] = pq.top(); pq.pop();
    ans = max(ans, time);
    if (!m) continue;
    m--;
    pq.push({time + t[id], id});
  }

  cout << ans;
}