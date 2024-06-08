#include <bits/stdc++.h>
using namespace std;

int water[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  for (int j = 1; j <= t; j++) {
    memset(water, 0, sizeof(water));
    int n; cin >> n;
    int st, en; cin >> st >> en;
    
    while (n--) {
      int s, e, f; cin >> s >> e >> f;
      for (int i = s; i <= e; i++)
        water[i] += f;
    }

    int ans = 0;
    for (int i = st; i <= en; i++)
      ans += water[i];
    cout << "Data Set " << j << ":\n";
    cout << ans << '\n';
    cout << '\n';
  }
}
