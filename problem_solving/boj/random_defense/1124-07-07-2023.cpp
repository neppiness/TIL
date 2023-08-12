#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int least_prd[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(least_prd, 0x7f, sizeof(least_prd));
  for (int i = 2; i <= 100'000; i++) {
    least_prd[i] = min(least_prd[i], i);
    for (int j = i; (ll)j * i <= 100'000; j++)
      least_prd[j * i] = min(least_prd[j * i], i);
  }

  int a, b; cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    int tmp = i, cnt = 0;
    while (tmp != 1) {
      cnt++;
      tmp /= least_prd[tmp];
    }
    ans += (least_prd[cnt] == cnt);
  }
  cout << ans;
}