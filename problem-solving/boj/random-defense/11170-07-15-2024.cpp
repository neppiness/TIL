#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int st, en; cin >> st >> en;
    int cnt = 0;
    for (int i = st; i <= en; i++) {
      string s = to_string(i);
      for (char c : s) {
        cnt += (c == '0');
      }
    }
    cout << cnt << '\n';
  }
}
