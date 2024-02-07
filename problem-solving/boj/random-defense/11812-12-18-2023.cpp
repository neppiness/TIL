#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
int k, q;

pair<ll, ll> get_coordinates(ll x) {
  ll fl = 0, fi, la;
  for (ll kpo = 1; ; kpo *= k) {
    fi = (kpo - 1) / (k - 1) + 1;
    la = (kpo*k - 1) / (k - 1);
    if (x <= la) break;
    fl++;
  }
  return {fl, x - fi};
}

int solve() {
  ll st, en;
  cin >> st >> en;

  pair<ll, ll> co_st = get_coordinates(st);
  pair<ll, ll> co_en = get_coordinates(en);

  if (co_st < co_en) swap(co_st, co_en);

  int diff = co_st.first - co_en.first;
  int ans = diff;
  while (diff--) {
    co_st = {co_st.first - 1, co_st.second / k};
  }
  while (co_st != co_en) {
    co_st = {co_st.first - 1, co_st.second / k};
    co_en = {co_en.first - 1, co_en.second / k};
    ans += 2;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> q;
  while (q--) cout << solve() << '\n';
}
