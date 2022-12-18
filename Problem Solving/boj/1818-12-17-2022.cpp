#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int mx = 0;
  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    mx = max(abs(x - i), mx);
  }
  cout << mx;
}