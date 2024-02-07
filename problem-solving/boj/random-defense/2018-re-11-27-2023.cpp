#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  long long tot = 0;
  int cnt = 0, en = 1;
  for (int st = 1; st <= n; st++) {
    while (en <= n && tot < n) tot += en++;
    if (tot == n) cnt++;
    tot -= st;
  }
  cout << cnt;
}
