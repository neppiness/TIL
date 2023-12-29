#include <bits/stdc++.h>
using namespace std;

const int MX = (1 << 20);
int a[MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int k; cin >> k;

  for (int i = 0; i < k; i++) {
    sort(a + n/k * i, a + n/k * (i + 1));
  }
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
}
