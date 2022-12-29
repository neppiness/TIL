#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<int, vector<int>, greater<int>> pq;

ll solve() {
  int n; cin >> n;
  while(n--) {
    int x; cin >> x;
    pq.push(x);
  }

  ll ans = 0;
  while(pq.size() != 1) {
    int x = pq.top(); pq.pop();
    int y = pq.top(); pq.pop();
    ans += x + y;
    pq.push(x + y);
    cout << x + y << ' ';
  }
  pq.pop();
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) cout << solve() << '\n';
}