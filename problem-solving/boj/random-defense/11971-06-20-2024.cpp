#include <bits/stdc++.h>
using namespace std;

int mx;
int d[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int st = 0;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    int en = st + a;
    for (; st < en; st++)
      d[st] = b;
  }
  st = 0;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    int en = st + a;
    for (; st < en; st++) {
      mx = max(mx, b - d[st]);
    }
  }
  cout << mx;
}
