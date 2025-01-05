#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> sc;
unordered_map<string, bool> is_used;
unordered_map<string, int> memo;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  
  for (int i = 0; i < n; i++) {
    string s; int x;
    cin >> s >> x;
    sc.push_back({x, s});
    memo[s] = x;
  }

  int sum = 0;
  for (int i = 0; i < k; i++) {
    string s; cin >> s;
    sum += memo[s];
    is_used[s] = 1;
  }

  sort(sc.begin(), sc.end());
  int mn = sum, mx = sum;
  
  int cnt = m - k;
  for (int i = 0; i < n; i++) {
    if (cnt == 0) break;
    auto [x, s] = sc[i];
    if (is_used[s]) continue;
    mn += x;
    cnt--;
  }

  cnt = m - k;
  for (int i = n - 1; i >= 0; i--) {
    if (cnt == 0) break;
    auto [x, s] = sc[i];
    if (is_used[s]) continue;
    mx += x;
    cnt--;
  }
  cout << mn << ' ' << mx;
}
