#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> memo;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  int cnt = 0;
  while (t--) {
    string ori; cin >> ori;
    int n = ori.size();

    bool is_found = 0;
    for (int i = 0; i < n; i++) {
      string trans = "";
      for (int j = 0; j < n; j++) {
        trans += ori[(i + j) % n];
      }
      if (memo[trans]) is_found = 1;
    }
    if (!is_found) cnt++;

    for (int i = 0; i < n; i++) {
      string trans = "";
      for (int j = 0; j < n; j++) {
        trans += ori[(i + j) % n];
      }
      memo[trans] = 1;
    }
  }
  cout << cnt;
}
