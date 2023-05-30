#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int lmx = 33;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll x; cin >> x;
  if (x == 0) { cout << 0; return 0; }
  ll ans = 0;
  while (x != 0) {
    bool is_minus = 0;
    ll st = 0, en = 0;
    for (int i = 0; i < lmx; i++) {
      ll rng = ((ll)1 << i);
      if (is_minus) st -= rng;
      else en += rng;
      if (st <= x && x <= en) {
        ans |= rng;
        if (is_minus) x += rng;
        else x -= rng;
        break;
      }
      is_minus = !is_minus;
    }
  }
  stack<int> st;
  while (ans != 0) {
    st.push(ans % 2);
    ans /= 2;
  }
  while(!st.empty()) {
    cout << st.top(); st.pop();
  }
}