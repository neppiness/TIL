#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    cnt[s]++;
    mx = max(mx, cnt[s]);
  }
  set<string> s;
  for (const auto &pr : cnt)
    if (pr.second == mx)
      s.insert(pr.first);
  
  for (string st : s)
    cout << st << '\n';
}
