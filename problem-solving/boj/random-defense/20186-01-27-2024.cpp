#include <bits/stdc++.h>
using namespace std;

int a[5002];
int sorted_a[5002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sorted_a[i] = a[i];
  }

  sort(sorted_a, sorted_a + n, greater<int>());
  int ans = 0;
  for (int i = 0; i < k; i++)
    ans += sorted_a[i];
  ans -= (k - 1) * k / 2;
  cout << ans;
}
