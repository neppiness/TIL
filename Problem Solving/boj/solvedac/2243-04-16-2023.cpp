#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;
const int ROOT = 1;

int t, i, j;
int cnt[MX + 2], cnts[4*MX + 2];

int update(int st, int en, int cur) {
  if(en < t || st > t) return cnts[cur];
  if(st == en) return cnts[cur] = cnt[st];
  int mid = (st + en) / 2;
  return cnts[cur] = update(st, mid, cur*2)
      + update(mid + 1, en, cur*2 + 1);
}

void put() {
  int no;
  cin >> t >> no;
  cnt[t] += no;
  update(1, MX, ROOT);
}

int rgnchk(int st, int en, int cur) {
  if(j < st || en < i) return 0;
  if(i <= st && en <= j) return cnts[cur];
  int mid = (st + en) / 2;
  return rgnchk(st, mid, cur*2)
      + rgnchk(mid + 1, en, cur*2 + 1);
}

void pop() {
  int st = 1, en = MX, rnk;
  cin >> rnk;

  while(st != en) {
    int mid = (st + en) / 2 + 1;
    i = 1, j = mid;
    if(rgnchk(1, MX, ROOT) >= rnk) en = mid - 1;
    else st = mid;
  }
  if(rgnchk(1, MX, ROOT) < rnk) {
    j = st + 1;
    if(rgnchk(1, MX, ROOT) == rnk) st++;
  }
  cout << st << '\n';
  cnt[st]--; t = st;
  update(1, MX, ROOT);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--) {
    int code; cin >> code;
    if(code == 2) put();
    else pop();
  }
}