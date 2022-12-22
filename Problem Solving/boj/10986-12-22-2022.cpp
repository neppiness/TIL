#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ps;

int mcnt[1002]; // mod count

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  const int M = m;

  mcnt[0] = 1;

  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    x %= M;
    ps += x;
    if(ps >= M) ps -= M;
    mcnt[ps]++;
  }
  
  ll ans = 0;
  for(int i = 0; i < M; i++)
    ans += ((ll)mcnt[i] * ((ll)mcnt[i] - 1)) / 2;

  cout << ans;
}