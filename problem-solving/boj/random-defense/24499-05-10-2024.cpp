#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int sum = 0;
  for (int i = 0; i < k; i++)
    sum += a[i];

  int mx = sum;
  for (int i = 0; i < n; i++) {
    sum += (a[(i + k) % n] - a[i]);
    mx = max(mx, sum);
  }
  cout << mx;
}
