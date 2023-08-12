#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll mx;
stack<pair<int, int>> stk;

ll solve() {
  int cur, prv, st;
  mx = 0;
  for(int i = 0; i < n; i++) {
    cin >> cur;
    st = i;
    while(!stk.empty() && stk.top().first > cur) {
      tie(prv, st) = stk.top(); stk.pop();
      mx = max(mx, (ll)prv*(i - st));
    }
    stk.push({cur, st});
  }
  while(!stk.empty()) {
    tie(prv, st) = stk.top(); stk.pop();
    mx = max(mx, (ll)prv*(n - st));
  }
  return mx;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n) {
    cout << solve() << '\n';
    cin >> n;
  }
}