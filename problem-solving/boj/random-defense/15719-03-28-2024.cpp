#include <bits/stdc++.h>
using namespace std;

int a[10'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[x]++;
  }

  for (int i = 0; i < 10'000'002; i++) {
    if (a[i] == 2) {
      cout << i;
      return 0;
    }
  }
}
