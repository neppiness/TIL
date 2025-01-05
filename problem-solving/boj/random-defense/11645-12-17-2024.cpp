#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> memo;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    while (n--) {
      string s; cin >> s;
      memo[s] = 1;
    }
    int ans = 0;
    for (auto p : memo) ans++;
    cout << ans << '\n';
    memo = unordered_map<string, bool>();
  }
}
