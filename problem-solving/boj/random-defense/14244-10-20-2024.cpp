#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int root = 0;
  for (int i = 1; i < m; i++) {
    cout << root << ' ' << i << '\n';
  }

  for (int i = m; i < n; i++) {
    cout << root << ' ' << i << '\n';
    root = i;
  }
}
