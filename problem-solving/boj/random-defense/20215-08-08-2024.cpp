#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(13);
  cout << fixed;

  int n, m; cin >> n >> m;
  cout << n + m -sqrt(n * n + m * m);
}
