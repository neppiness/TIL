#include <bits/stdc++.h>
using namespace std;

int a[200'002];
int n, k, ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  int st = 0, en = 1, sum = a[0];
  while (en <= n) {
    if (sum >= k) {
      ans += (sum == k);
      sum -= a[st++];
    } else {
      if (en == n) break;
      sum += a[en++];
    }
  }
  cout << ans;
}