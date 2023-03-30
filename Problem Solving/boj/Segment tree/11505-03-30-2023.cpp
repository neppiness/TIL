#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 1e+6;
const int MOD = 1'000'000'007;

int n, m, k;
int idx, tar, i, j;
int a[MX + 2];
ll muls[4*MX + 2];

ll init(int st, int en, int cur) {
  if(st == en) return muls[cur] = a[st];
  int mid = (st + en) / 2;
  muls[cur] = init(st, mid, cur*2) * init(mid + 1, en, cur*2 + 1);
  if(muls[cur] >= MOD) muls[cur] %= MOD;
  return muls[cur];
}

ll update(int st, int en, int cur) {
  if(st > idx || en < idx) return muls[cur];
  if(st == en) return muls[cur] = tar;
  int mid = (st + en) / 2;
  muls[cur] = update(st, mid, cur*2) * update(mid + 1, en, cur*2 + 1);
  if(muls[cur] >= MOD) muls[cur] %= MOD;
  return muls[cur];
}

ll print(int st, int en, int cur) {
  if(st > j || en < i) return 1;
  if(i <= st && en <= j) return muls[cur];
  int mid = (st + en) / 2;
  ll mul1 = print(st, mid, cur*2);
  ll mul2 = print(mid + 1, en, cur*2 + 1);
  if(mul1 >= MOD) mul1 %= MOD;
  if(mul2 >= MOD) mul2 %= MOD;
  ll res = mul1 * mul2;
  if(res >= MOD) res %= MOD;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  
  init(1, n, 1);

  m += k;
  while(m--) {
    int code; cin >> code;
    if(code == 1) {
      cin >> idx >> tar;
      update(1, n, 1);
    } else {
      cin >> i >> j;
      cout << print(1, n, 1) << '\n';
    }
  }
}