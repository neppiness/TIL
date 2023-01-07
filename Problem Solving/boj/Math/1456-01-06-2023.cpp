#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 10'000'001;
bool isprime[MX];

ll calc(int pr, ll st, ll en) {
  st /= pr;
  en /= pr;

  ll cnt = 0;
  while(en != 0) {
    st /= pr;
    en /= pr;
    if(st == 0 && en != 0) cnt++;
  }
  return cnt;
}

ll solve(ll st, ll en) {
  ll ans = 0;
  for(ll i = 2; i < MX; i++) {
    if(!isprime[i]) continue;
    for(ll j = i; i * j < MX; j++)
      isprime[i * j] = 0;
    ans += calc(i, st - 1, en);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll st, en;
  cin >> st >> en;

  fill(isprime, isprime + MX, 1);
  cout << solve(st, en);
}