#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;

ll solve(ll x) { // i*j (i, j <= n) 꼴 정수 중에서 x보다 작은 정수의 개수
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    ll st = 0, en = n;
    while(st < en) {
      ll j = (st + en) / 2 + 1;
      if(i * j >= x) en = j - 1;
      else st = j;
    }
    ans += st;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  ll st = 1, en = n * n;
  while(st < en) {
    ll mid = (st + en) / 2 + 1;
    ll cnt = solve(mid);
    if(cnt < k) st = mid;
    else en = mid - 1;
  }
  cout << st;
}