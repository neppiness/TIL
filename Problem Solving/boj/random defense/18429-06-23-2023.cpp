#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[10], c[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i]; c[i] = i;
  }

  int ans = 0;
  do {
    int w = 500;
    bool is_valid = 1;
    for (int i = 0; i < n; i++) {
      w += a[c[i]]; w -= k;
      if (w < 500) is_valid = 0;
    }
    ans += is_valid;
  } while (next_permutation(c, c + n));
  cout << ans;
}