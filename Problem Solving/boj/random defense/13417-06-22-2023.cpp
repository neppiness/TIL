#include <bits/stdc++.h>
using namespace std;

deque<char> dq;

void solve() {
  int n; cin >> n;

  char c; cin >> c;
  dq.push_back(c);
  while (--n) {
    cin >> c;
    if (dq.front() >= c) dq.push_front(c);
    else dq.push_back(c);
  }

  while (!dq.empty()) {
    cout << dq.front(); dq.pop_front();
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}