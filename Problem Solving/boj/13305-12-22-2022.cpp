#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dist[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n - 1; i++)
    cin >> dist[i];

  ll tot = 0;
  ll cost; cin >> cost;
  for(int i = 0; i < n - 1; i++) {
    tot += dist[i] * cost;
    ll c; cin >> c;
    cost = min(c, cost);
  }
  cout << tot;
}