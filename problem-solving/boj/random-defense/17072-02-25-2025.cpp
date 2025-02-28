#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int r, g, b; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> r >> g >> b;
      int calc = 2126 * r + 7152 * g + 722 * b;
      if (calc < 510'000) cout << '#';
      else if (calc < 1'020'000) cout << 'o';
      else if (calc < 1'530'000) cout << '+';
      else if (calc < 2'040'000) cout << '-';
      else cout << '.';
    }
    cout << '\n';
  }
}
