#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  long long sum = 1;
  int cnt = 0;
  int st = 1, en = 1;
  while (en <= n) {
    if (sum == n) cnt++;
    if (sum > n) {
      sum -= st++;
    } else {
      sum += ++en;
    }
  }
  cout << cnt;
}
