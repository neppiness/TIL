#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, q;

pair<ll, ll> get_coordinate(ll x) {
  ll cnt = 0;
  for (ll po = 1; 1; po *= k) {
    ll st = (po - 1) / (k - 1) + 1;
    ll en = (po * k - 1) / (k - 1);
    if (en < x) {
      cnt++;
      continue;
    }
    return {cnt, x - st};
  }
}

pair<ll, ll> move(pair<ll, ll> coord, ll diff) {
  while (diff--) {
    coord = {coord.first - 1, coord.second / k};
  }
  return coord;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> q;

  if (k == 1) {
    while (q--) {
      ll a, b; cin >> a >> b;
      cout << max(a, b) - min(a, b) << '\n';
    }
    return 0;
  }

  while (q--) {
    ll a, b; cin >> a >> b;
    if (a < b) swap(a, b); // a가 항상 큰 값

    pair<ll, ll> coord_a = get_coordinate(a);
    pair<ll, ll> coord_b = get_coordinate(b);

    ll diff = coord_a.first - coord_b.first;
    coord_a = move(coord_a, diff);
    while (coord_a != coord_b) {
      coord_a = move(coord_a, 1);
      coord_b = move(coord_b, 1);
      diff += 2;
    }
    cout << diff << '\n';
  }
}
