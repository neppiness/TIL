#include <bits/stdc++.h>
using namespace std;

bool solve() {
  string s; cin >> s;
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (!st.empty() && st.top() == s[i]) {
      st.pop();
    } else {
      st.push(s[i]);
    }
  }
  return st.empty();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  int ans = 0;
  while (t--) ans += solve();
  cout << ans;
}
