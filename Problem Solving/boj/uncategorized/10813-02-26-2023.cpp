#include <bits/stdc++.h>
using namespace std;

int a[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++)
    a[i] = i;
  while(m--) {
    int u, v; cin >> u >> v;
    swap(a[u], a[v]);
  }
  for(int i = 1; i <= n; i++)
    cout << a[i] << ' ';
}