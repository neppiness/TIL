#include <bits/stdc++.h>
using namespace std;

int h[1'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> h[i];

  sort(h, h + n);

  for (int i = 0; i < n; i++)
    if (h[i] <= k) k++;

  cout << k;
}
