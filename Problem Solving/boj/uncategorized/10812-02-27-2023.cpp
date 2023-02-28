#include <bits/stdc++.h>
using namespace std;

const int MX = 100 + 2;
int a[MX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++)
    a[i] = i;
  while(m--) {
    int i, j, k;
    cin >> i >> j >> k;
    rotate(a + i, a + k, a + j + 1);
  }
  for(int i = 1; i <= n; i++)
    cout << a[i] << ' ';
}