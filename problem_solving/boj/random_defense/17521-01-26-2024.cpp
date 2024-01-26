#include <bits/stdc++.h>
using namespace std;

int n;
long long w;
int a[17];

// idx번째 날의 cash, no_of_coin으로부터 얻을 수 있는 최대 현금
long long solve(int idx, long long cash, long long no_of_coin) {
  if (idx == n) {
    return cash + no_of_coin * a[n];
  }

  int nxt = idx + 1;
  long long ret = solve(nxt, cash, no_of_coin);
  ret = max(ret, solve(nxt, cash % a[idx], no_of_coin + cash / a[idx]));
  return max(ret, solve(nxt, cash + no_of_coin * a[idx], 0));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> w;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  cout << solve(1, w, 0); 
}
