#include <bits/stdc++.h>
using namespace std;

int n, a[10002], diff[10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);
  for (int i = 0; i < n - 1; i++)
    diff[i] = a[i + 1] - a[i];
  sort(diff, diff + n - 1);

  int sum = 0;
  for (int i = 0; i < n - k; i++)
    sum += diff[i];
  cout << sum;
}