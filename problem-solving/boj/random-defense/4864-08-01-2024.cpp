#include <bits/stdc++.h>
using namespace std;

int a[10'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int rew = 1;
  int b = 1;
  int cnt = 0;
  for (int i = 1; i <= 10000; i++) {
    a[i] = a[i - 1] + rew;
    cnt++;
    if (cnt != b) continue;
    rew++; b++;
    cnt = 0;
  }

  int n; cin >> n;
  while (n) {
    cout << n << ' ' << a[n] << '\n';
    cin >> n;
  }
}
