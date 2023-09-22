#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int n, atk;
tuple<int, int, int> info[123'456];

bool solve(ll mx_hp) {
  ll cur_atk = atk;
  ll cur_hp = mx_hp;
  for (int i = 0; i < n; i++) {
    auto [t, a, h] = info[i];
    if (t == 1) { // monster
      ll damage_cnt = h / cur_atk;
      if (h % cur_atk == 0) damage_cnt--;
      cur_hp -= damage_cnt * a;
    } else { // potion
      cur_hp = min(cur_hp + h, mx_hp);
      cur_atk += a;
    }
    if (cur_hp <= 0) return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> atk;
  for (int i = 0; i < n; i++) {
    int t, a, h;
    cin >> t >> a >> h;
    info[i] = {t, a, h};
  }

  ll st = 1, en = INF;
  while (st < en) {
    ll mid = (st + en) / 2;
    if (solve(mid)) en = mid;
    else st = mid + 1;
  }
  cout << st;
}
