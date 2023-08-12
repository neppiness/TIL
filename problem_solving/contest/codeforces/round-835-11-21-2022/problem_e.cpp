#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[200'002];
int tmp[200'002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    ll mx = 0;
    ll sum = 0;

    int n; cin >> n;
    int zeroOnLeft = n - 1, oneOnRight = 0;

    fill(a, a + n + 1, 0);
    fill(tmp, tmp + n + 1, 0);

    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(a[i] == 0) zeroOnLeft = min(i, zeroOnLeft);
      else oneOnRight = max(i, oneOnRight);
    }

    for(int i = n - 1; i >= 0; i--) {
      if(a[i] == 0)
        tmp[i] = tmp[i + 1] + 1;
      else {
        tmp[i] = tmp[i + 1];
        sum += tmp[i];
      }
    }

    mx = sum;
    sum = 0;

    a[zeroOnLeft] = 1;
    for(int i = n - 1; i >= 0; i--) {
      if(a[i] == 0)
        tmp[i] = tmp[i + 1] + 1;
      else {
        tmp[i] = tmp[i + 1];
        sum += tmp[i];
      }
    }

    mx = max(mx, sum);
    sum = 0;

    a[zeroOnLeft] = 0;
    a[oneOnRight] = 0;
    for(int i = n - 1; i >= 0; i--) {
      if(a[i] == 0)
        tmp[i] = tmp[i + 1] + 1;
      else {
        tmp[i] = tmp[i + 1];
        sum += tmp[i];
      }
    }

    mx = max(mx, sum);
    cout << mx << '\n';
  }
}