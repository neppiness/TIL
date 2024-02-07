#include <bits/stdc++.h>
using namespace std;

vector<int> pr;
bool is_pr[1002];

void solve() {
  int x; cin >> x;
  for (int i = 0; i < pr.size(); i++)
    for (int j = i; j < pr.size(); j++)
      for (int k = j; k < pr.size(); k++) {
        if (pr[i] + pr[j] + pr[k] != x) continue;
        cout << pr[i] << ' ' << pr[j] << ' ' << pr[k] << '\n';
        return;
      }
  cout << 0 << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(is_pr, is_pr + 1001, 1);
  is_pr[0] = 0; is_pr[1] = 0;

  for (int i = 2; i <= 1000; i++) {
    if (is_pr[i]) pr.push_back(i);
    for (int j = i; i * j <= 1000; j++) {
      is_pr[i * j] = 0;
    }
  }
  int t; cin >> t;
  while (t--) solve();
}
