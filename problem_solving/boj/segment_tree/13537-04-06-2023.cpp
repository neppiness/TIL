#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;
const int ROOT = 1;

int i, j, n, m, k;
int a[MX + 2], mins[4 * MX];

int init(int st, int en, int cur) {
  if(st == en) return mins[cur] = a[st];
  int mid = (st + en) / 2;
  return mins[cur] = min(init(st, mid, cur*2), init(mid + 1, en, cur*2 + 1));
}

int solve(int st, int en, int cur) {
  if(en < i || j < st) return 0;
  if(i <= st && en <= j)
    if(mins[cur] > k) return en - st + 1;
  if(st == en) return mins[cur] > k;
  int mid = (st + en) / 2;
  return solve(st, mid, cur*2) + solve(mid + 1, en, cur*2 + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> a[i];

  init(1, n, ROOT);

  cin >> m;
  while(m--) {
    cin >> i >> j >> k;
    cout << solve(1, n, ROOT) << '\n';
  }
}