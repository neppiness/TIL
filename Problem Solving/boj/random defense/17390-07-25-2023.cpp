#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[300'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a  + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    a[i] += a[i - 1];

  while (m--)  {
    int u, v; cin >> u >> v;
    u--;
    cout << a[v] - a[u] << '\n';
  }
}