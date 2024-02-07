#include <bits/stdc++.h>
using namespace std;

bool solve() {
  string a; cin >> a;
  int sz = a.size() - 1;
  for(int i = 0; i < sz; i++) {
    if(a[i] == a[sz - i]) continue;
    return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << solve();
}