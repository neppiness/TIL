#include <bits/stdc++.h>
using namespace std;

int seq[20'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, a, d;
  cin >> n >> a >> d;

  for (int i = 0; i < n; i++)
    cin >> seq[i];

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a != seq[i]) continue;
    cnt++;
    a += d;
  }
  cout << cnt;
}
