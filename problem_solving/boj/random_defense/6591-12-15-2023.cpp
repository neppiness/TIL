#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  while (n != 0 || k != 0) {
    long long ans = 1;
    int k2 = n - k;
    k = min(k, k2);

    for (int i = 1; i <= k; i++) {
      ans *= (n - i + 1);
      ans /= i; 
    }
    cout << ans << '\n';
    cin >> n >> k;
  }
}
