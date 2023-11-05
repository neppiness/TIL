#include <bits/stdc++.h>
using namespace std;

set<int> ans;

int get_nxt(int x, int p) {
  int sum = 0;
  while (x) {
    int digit = x % 10;
    for (int i = 1; i < p; i++) {
      digit *= (x % 10);
    }
    sum += digit;
    x /= 10;
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, p;
  cin >> a >> p;

  while (1) {
    int b = get_nxt(a, p);
    cout << b << '\n';
    auto it = ans.find(b);
    if (it != ans.end()) break;
    ans.insert(b);
    swap(a, b);
  }
  for (int x : ans) cout << x << '\n';

  cout << ans.size();
}
