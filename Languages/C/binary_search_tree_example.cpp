#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  set<int> s({161, 161, 188, 154, 180, 172});
  auto it = s.lower_bound(156);
  cout << *prev(it);
}