#include <bits/stdc++.h>
using namespace std;

unordered_map<string, set<string>> m;
set<string> key;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    string a, b; cin >> a >> b;
    key.insert(a);
    m[a].insert(b);
  }

  for (string k : key) {
    set<string> s = m[k];
    for (auto it = s.rbegin(); it != s.rend(); it++) {
      cout << k << ' ' << *it << '\n';
    }
  }
}
