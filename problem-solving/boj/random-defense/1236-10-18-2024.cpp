#include <bits/stdc++.h>
using namespace std;

bool has_guard[52][52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (int j = 0; j < m; j++) {
      has_guard[i][j] = (s[j] == 'X');
    }
  }
  cout << cnt;
}
