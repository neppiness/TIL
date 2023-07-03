#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e9;

unordered_map<ll, string> dp;
queue<ll> q;
ll st, en;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> st >> en;
  if (st == en) { cout << 0; return 0; }

  q.push(st);
  while (!q.empty()) {
    ll cur = q.front(); q.pop();
    if (cur == en) { cout << dp[cur]; return 0; }

    string s = dp[cur];
    if (cur * cur <= mx && dp[cur * cur].size() == 0) {
      dp[cur * cur] = s + '*'; q.push(cur * cur);
    }
    if (2 * cur <= mx && dp[2 * cur].size() == 0) {
      dp[2 * cur] = s + '+'; q.push(2 * cur);
    }
    if (dp[0].size() == 0) {
      dp[0] = s + '-'; q.push(0);
    }
    if (cur != 0 && dp[1].size() == 0) {
      dp[1] = s + '/'; q.push(1);
    }
  }
  cout << -1;
}