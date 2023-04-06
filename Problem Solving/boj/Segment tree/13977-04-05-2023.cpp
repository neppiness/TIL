#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;
const int MX = 4'000'000;
const int ROOT = 1;

int n, r, i, j;
ll muls[4 * MX];

ll init(int st, int en, int cur) {
  if(st == en) return muls[cur] = st;
  int mid = (st + en) / 2;
  ll lf = init(st, mid, cur*2);
  ll rf = init(mid + 1, en, cur*2 + 1);
  return muls[cur] = (lf * rf) % MOD;
}

ll mul(int st, int en, int cur) {
  if(en < i || j < st) return 1;
  if(i <= st && en <= j) return muls[cur];
  int mid = (st + en) / 2;
  return mul(st, mid, cur*2) * mul(mid + 1, en, cur*2 + 1) % MOD;
}

ll pow(ll no, int po) { // return no^po
  if(po == 1) return no;
  ll hpow = pow(no, po / 2);
  hpow *= hpow; hpow %= MOD;
  ll ans = 1;
  if(po % 2) ans = no;
  return (ans * hpow) % MOD; 
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  init(0, MX, ROOT);

  int m; cin >> m;
  while(m--) {
    cin >> n >> r;
    i = 1, j = r;
    ll rfact = mul(0, MX, ROOT);
    ll inv_rfact = pow(rfact, MOD - 2);

    i = n - r + 1, j = n;
    ll nPr = mul(0, MX, ROOT);
    ll ans = (nPr * inv_rfact) % MOD;
    cout << ans << '\n';
  }
}