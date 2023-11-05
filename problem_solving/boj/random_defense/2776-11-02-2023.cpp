#include <bits/stdc++.h>
using namespace std;

void solve() {
  unordered_map<int, bool> record;
  int n; cin >> n;
  while (n--) {
    int x; cin >> x;
    record[x] = 1;
  }

  cin >> n;
  while (n--) {
    int x; cin >> x;
    cout << record[x] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}

