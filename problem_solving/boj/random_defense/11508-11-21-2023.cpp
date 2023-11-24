#include <bits/stdc++.h>
using namespace std;

int n, a[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n; 
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  int en = n;
  int cnt = 0, tot = 0;
  while (--en >= 0) {
    if (cnt == 2) {
      cnt = 0;
      continue;
    }
    tot += a[en];
    cnt++;
  }
  cout << tot;
}
