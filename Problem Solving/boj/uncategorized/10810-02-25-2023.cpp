#include <bits/stdc++.h>
using namespace std;

int a[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(m--) {
    int st, en, x;
    cin >> st >> en >> x;
    for(int i = st; i <= en; i++)
      a[i] = x;
  }
  for(int i = 1; i <= n; i++)
    cout << a[i] << ' ';
}