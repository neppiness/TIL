#include <bits/stdc++.h>
using namespace std;

char a[12][12];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  bool is = 1;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if (a[i][j / 2] == s[j]) continue;
      is = 0;
    }
  }
  if (is) {
    cout << "Eyfa";
  } else {
    cout << "Not Eyfa";
  }
}
