#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    int x; cin >> x;
    s.insert(x);
  }
  for (int x : s) cout << x << ' ';
}