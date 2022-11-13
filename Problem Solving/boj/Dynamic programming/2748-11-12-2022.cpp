#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll p[94];

ll solve(int n) {
  for(int i = 2; i <= n; i++)
    p[i] = p[i - 1] + p[i - 2];
  return p[n];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  p[0] = 0;
  p[1] = 1;
  cout << solve(n);
}