#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;
const int INF = 0x7f7f7f7f;

int n, m, i, j;
int a[MX + 2];
int mn[4 * MX + 2], mx[4 * MX + 2];

// code: 0 for min, 1 for max
int init(int st, int en, int cur, bool code) {
  if(st == en)
    return code ? mx[cur] = a[st] : mn[cur] = a[st];
  int mid = (st + en) / 2;
  int lt = init(st, mid, cur * 2, code);
  int rt = init(mid + 1, en, cur * 2 + 1, code);
  return code ? mx[cur] = max(lt, rt) : mn[cur] = min(lt, rt);
}

int q(int st, int en, int cur, bool code) {
  if(en < i || st > j) return code ? -INF : INF;
  if(i <= st && en <= j) return code ? mx[cur] : mn[cur];
  int mid = (st + en) / 2;
  int lt = q(st, mid, cur * 2, code);
  int rt = q(mid + 1, en, cur * 2 + 1, code);
  return code ? max(lt, rt) : min(lt, rt);
}

void q() {
  cin >> i >> j;
  cout << q(1, n, 1, 0) << ' ';
  cout << q(1, n, 1, 1) << '\n';
}

void init() {
  init(1, n, 1, 0);
  init(1, n, 1, 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  
  init();
  while(m--) q();
}