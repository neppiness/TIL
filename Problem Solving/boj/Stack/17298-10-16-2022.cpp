#include <bits/stdc++.h>
using namespace std;

int a[1'000'002];
int aidx[1'000'002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  fill(aidx, aidx + n, -1);

  int i = 0;
  for(; i < n; i++) cin >> a[i];

  while(--i) {
    int cur = i;
    if(a[i] > a[i - 1]) aidx[i - 1] = i;
    else while(cur != -1 && a[cur] <= a[i - 1])
      cur = aidx[cur];
    if(cur != -1) aidx[i - 1] = cur;
  }
  for(; i < n; i++) {
    int ansidx = aidx[i];
    if(ansidx == -1) cout << -1 << ' ';
    else cout << a[ansidx] << ' ';
  }
}