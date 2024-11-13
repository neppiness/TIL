#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n / 2; i++) {
    cout << 1 << ' ' << 2 << ' ';
  }
  if (n % 2) cout << 3;
}
