#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[300'002];

bool solve(const int mod) {
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    cnt += a[i] / mod;
    cnt += (a[i] % mod != 0);
  }
  return (cnt <= n);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i];

  int st = 1, en = 0x3f3f3f3f;
  while (st < en) {
    int mid = (st + en) / 2;
    if (solve(mid)) en = mid;
    else st = mid + 1;
  }
  cout << st;
}