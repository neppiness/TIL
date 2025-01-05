#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, s, h;
  cin >> t >> s >> h;
  
  int n = t + h + 1;
  int m = s * 2 + 3;

  for (int i = 0; i < t; i++) {
    for (int j = 0; j < m; j++) {
      if (j == 0 || j == s + 1 || j == m - 1) {
        cout << '*';
      } else {
        cout << ' ';
      }
    }
    cout << '\n';
  }

  for (int j = 0; j < m; j++) cout << '*';
  cout << '\n';

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < s + 2; j++) {
      if (j == s + 1) cout << '*';
      else cout << ' ';
    }
    cout << '\n';
  }
}
