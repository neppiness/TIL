#include <bits/stdc++.h>
using namespace std;

int a[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    a[i] = a[i - 1] + x;
  }
  
  int mx = -0x7f7f7f7f;
  for(int i = k; i <= n; i++)
    mx = max(mx, a[i] - a[i - k]);
  
  cout << mx;
}
