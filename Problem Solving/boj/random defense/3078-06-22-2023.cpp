#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
vector<int> a[22];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    a[s.size()].push_back(i);
  }

  ll ans = 0;
  for (int len = 2; len <= 20; len++) {
    int st = 0, en = 0;
    for (; st < a[len].size(); st++) {
      while (en < a[len].size() && a[len][en] - a[len][st] <= k) en++;
      if (en == a[len].size()) break;
      ans += en - st - 1;
    }
    while (++st < a[len].size()) ans += en - st;
  }
  cout << ans;
}