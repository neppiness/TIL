#include <bits/stdc++.h>
using namespace std;

int a[100'002];
int mn = 0x7f7f7f7f;
int ans[2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  int st = 0, en = n - 1;
  while(st < en) {
    int sum = a[en] + a[st];
    if(abs(sum) < mn) {
      mn = abs(sum);
      ans[0] = a[st];
      ans[1] = a[en];
    }
    if(sum > 0) en--;
    else if(sum < 0) st++;
    else break;
  }
  cout << ans[0] << ' ' << ans[1];
}