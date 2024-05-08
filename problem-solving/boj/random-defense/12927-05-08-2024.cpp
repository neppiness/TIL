#include <bits/stdc++.h>
using namespace std;

bool a[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  for (int i = 1; i <= n; i++) {
    a[i] = (s[i - 1] == 'Y');
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!a[i]) continue;
    for (int j = i; j <= n; j += i) {
      a[j] = !a[j];
    }
    ans++;
  }
  cout << ans;
}
