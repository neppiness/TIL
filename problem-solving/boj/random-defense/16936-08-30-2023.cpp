#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
set<ll> s;
unordered_map<ll, vector<ll>> edge;
unordered_map<ll, int> ind;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    ll x; cin >> x;
    s.insert(x);
  }

  for (ll x : s) {
    vector<ll> tmp;

    ll d = x * 2;
    auto it = s.find(d);
    if (it != s.end()) {
      ll y = (*it);
      tmp.push_back(y);
      ind[y]++;
    }

    if (x % 3 == 0) {
      d = x / 3;
      it = s.find(d);
      if (it != s.end()) {
        ll y = (*it);
        tmp.push_back(y);
        ind[y]++;
      }
    }

    if (tmp.size()) edge[x] = tmp;
  }

  ll st;
  for (ll x : s)
    if (ind[x] == 0) st = x;

  queue<ll> q;
  q.push(st);
  while (!q.empty()) {
    ll cur = q.front(); q.pop();
    cout << cur << ' ';
    for (ll nxt : edge[cur]) {
      ind[nxt]--;
      if (ind[nxt] == 0) q.push(nxt);
    }
  }
}
