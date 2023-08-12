#include <bits/stdc++.h>
using namespace std;

int a[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  int x; cin >> x;
  int st = 0, en = n - 1;
  int cnt = 0;

  while(st < en) {
    if(a[st] + a[en] > x) en--;
    else if(a[st] + a[en] < x) st++;
    else { cnt++; st++; en--; }
  }
  cout << cnt;
}
