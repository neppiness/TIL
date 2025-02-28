#include <bits/stdc++.h>
using namespace std;

int a[502][502];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      string s; cin >> s;
      for (char c : s) {
        a[i][j] += (c == '9');
      }
    }
  }
  int tot = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      sum += a[i][j];
    }
    tot += sum;
    mx = max(mx, sum);
  }

  for (int j = 0; j < m; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i][j];
    }
    mx = max(mx, sum);
  }
  cout << tot - mx;
}
