#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cache[55]; // 숫자 2^idx 이하의 모든 수가 갖고 있는 1의 개수

ll solve(int x) {
  ll ans = 0; int cnt = 0;
  for(int i = 55; i >= 0; i--) {
    ll chk = ((ll)1 << i);
    if(x & chk) {
      ans += cache[i] + chk * cnt;
      cnt++;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(ll i = 0; i <= 55; i++)
    cache[i] = i * ((ll)1 << i) / 2 + 1;

  cout << solve(7);
  return 0;

  ll a, b; cin >> a >> b;
  cout << solve(b) - solve(a - 1);
}