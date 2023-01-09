#include <bits/stdc++.h>
using namespace std;

int n, ans;
stack<pair<int, int>> st; // {index, height}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  // cur: current, prv: previous
  for(int curidx = 0; curidx < n; curidx++) {
    int curh; cin >> curh;
    if(st.empty()) {
      st.push({curidx, curh});
      continue;
    }
    auto [prvidx, prvh] = st.top();
    if(prvh < curh) st.push({curidx, curh});
    if(prvh <= curh) continue;

    while(!st.empty() && (st.top().second > curh)) {
      tie(prvidx, prvh) = st.top(); st.pop();
      int ar = (curidx - prvidx) * prvh;
      ans = max(ans, ar);
    }
    st.push({prvidx, curh});
  }
  // post-process
  while(!st.empty()) {
    auto [prvidx, prvh] = st.top(); st.pop();
    int ar = (n - prvidx) * prvh;
    ans = max(ans, ar);
  }
  cout << ans;
}