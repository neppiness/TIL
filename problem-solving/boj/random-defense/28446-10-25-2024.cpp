#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> memo;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    int code; cin >> code;
    if (code == 1) {
      int x, w; cin >> x >> w;
      memo[w] = x;
    } else {
      int w; cin >> w;
      cout << memo[w] << '\n';
    }
  }
}
