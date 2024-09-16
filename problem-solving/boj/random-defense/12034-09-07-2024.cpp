#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int n; cin >> n;
    unordered_map<int, int> memo;
    for (int i = 0; i < 2*n; i++) {
      int x; cin >> x;
      if (!memo[x]) {
        cout << x << ' ';
        memo[x / 3 * 4]++;
      } else {
        memo[x]--;
      }
    }
    cout << '\n';
  }
}
