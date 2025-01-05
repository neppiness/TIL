#include <bits/stdc++.h>
using namespace std;

int sc[10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while (n != 0 && m != 0) {
    memset(sc, 0, sizeof(sc));
    set<int> t;
    
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int x; cin >> x;
        sc[x]++;
      }

    for (int i = 1; i <= 10'000; i++) {
      t.insert(sc[i]);
    }
    auto tt = t.end();
    tt--; tt--;

    for (int i = 1; i <= 10'000; i++)
      if (sc[i] == *tt) cout << i << ' ';
    cout << '\n';

    cin >> n >> m;
  }
}
