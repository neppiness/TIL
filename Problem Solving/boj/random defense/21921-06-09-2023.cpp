#include <bits/stdc++.h>
using namespace std;

int n, x;
int mx = 0, cnt = 0;
int a[250'000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int en = 0, sum = 0;
  while (en < x) {
    sum += a[en++];
    if (mx == sum) cnt++;
    if (mx < sum) {
      mx = sum; cnt = 1;
    }
  }

  int st = 0;
  while (en < n) {
    sum += a[en++] - a[st++];
    if (mx == sum) cnt++;
    if (mx < sum) {
      mx = sum; cnt = 1;
    }
  }

  if (!mx) cout << "SAD\n";
  else cout << mx << '\n' << cnt;
}