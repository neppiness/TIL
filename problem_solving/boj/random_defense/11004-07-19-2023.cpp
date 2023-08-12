#include <bits/stdc++.h>
using namespace std;

int mx = 0;
unordered_map<string, int> cnt;
set<string> keys;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s;
  while (n--) {
    cin >> s;
    cnt[s]++;
    keys.insert(s);
    mx = max(mx, cnt[s]);
  }
  for (auto k : keys) {
    if (cnt[k] != mx) continue;
    cout << k;
    return 0;
  }
}