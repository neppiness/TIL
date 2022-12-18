#include <bits/stdc++.h>
using namespace std;

set<int> a, b, c;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(n--) {
    int x; cin >> x;
    a.insert(x);
  }
  while(m--) {
    int x; cin >> x;
    b.insert(x);
    auto it = a.find(x);
    if(it != a.end()) c.insert(x);
  }
  cout << a.size() + b.size() - 2 * c.size();
}