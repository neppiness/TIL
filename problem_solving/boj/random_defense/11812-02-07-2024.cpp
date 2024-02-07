#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, q;
stack<int> sta, stb;

void transform(ll x, stack<int> &st) {
  while (!st.empty()) {
    st.pop();
  }
  if (x == 0) return;
  while (x) {
    ll rest = x % k;
    if (rest == 0) {
      x -= k;
      st.push(k);
    } else {
      st.push(rest);
    }
    x /= k;
  }
}

ll solve() {
  ll a, b; cin >> a >> b;
  a--; b--;
  transform(a, sta);
  transform(b, stb);

  while (!sta.empty() && !stb.empty()) {
    if (sta.top() != stb.top()) break;
    sta.pop(); stb.pop();
  }
  return sta.size() + stb.size();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> k >> q;
  while (q--) {
    cout << solve() << '\n';
  }
}
