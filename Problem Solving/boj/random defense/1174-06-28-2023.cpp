#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<ll> ans;

void setup(int selectable, ll no) {
  ans.insert(no);
  for (int cur = selectable; cur >= 0; cur--)
    setup(cur - 1, 10*no + cur);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup(9, 0);

  int n; cin >> n;
  int cnt = 1;
  auto it = ans.begin();
  
  while (cnt < n && it != ans.end()) { it++; cnt++; }
  if (it == ans.end()) { cout << -1; return 0; }
  cout << *it;
}