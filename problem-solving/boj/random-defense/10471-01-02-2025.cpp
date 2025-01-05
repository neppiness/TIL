#include <bits/stdc++.h>
using namespace std;

int p[102];
set<int> ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int w, n; cin >> w >> n;
  p[0] = 0; p[n + 1] = w;
  for (int i = 1; i <= n; i++)
    cin >> p[i];

  for (int i = 1; i <= n + 1; i++) {
    for (int j = 0; j < i; j++) {
      ans.insert(p[i] - p[j]);
    }
  }
  for (int x : ans)
    cout << x << ' ';
}
