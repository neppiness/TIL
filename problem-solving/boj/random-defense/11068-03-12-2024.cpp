#include <bits/stdc++.h>
using namespace std;

bool solve(int n) {
  for (int i = 2; i <= 64; i++) {
    int x = n;
    deque<int> dq;
    while (x) {
      dq.push_back(x % i);
      x /= i;
    }
    bool is_pal = 1;
    while (dq.size() > 1) {
      int a = dq.front(); dq.pop_front();
      int b = dq.back(); dq.pop_back();
      if (a != b) is_pal = 0;
    }
    if (is_pal) return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << solve(n) << '\n';
  }
}
