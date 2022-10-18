#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll mx;
stack<pair<int, int>> stk;

ll solve() {
  int x, cur, st;
  mx = 0;
  for(int i = 0; i < n; i++) {
    cin >> x;
    while(!stk.empty() && stk.top().first > x) {
      tie(cur, st) = stk.top();
      mx = max(mx, (ll)cur*(i - st));
      stk.pop();
    }
    stk.push({x, i});
  }
  while(!stk.empty()) {
    tie(cur, st) = stk.top();
    mx = max(mx, (ll)cur*(n - st));
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