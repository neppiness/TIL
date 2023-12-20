#include <bits/stdc++.h>
using namespace std;

int n, m;
int x[100'002];

bool solve(int h) {
  int mx = 0;
  for (int  i = 0; i < m; i++) {
    int lo = x[i] - h;
    int hi = x[i] + h;
    if (lo > mx) return 0;
    mx = hi;
  }
  return mx >= n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> x[i];

  int st = 1, en = 100'002;
  while (st < en) {
    int mid = (st + en)/2;
    if (solve(mid)) en = mid;
    else st = mid + 1;
  }
  cout << st;
}
