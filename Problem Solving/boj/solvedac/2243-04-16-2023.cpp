#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;
const int ROOT = 1;

int t, i, j;
int fr[MX + 2], frs[4*MX + 2];

int update(int st, int en, int cur) {
  if(en < t || st > t) return frs[cur];
  if(st == en) return frs[cur] = fr[st];
  int mid = (st + en) / 2;
  return frs[cur] = update(st, mid, cur*2)
      + update(mid + 1, en, cur*2 + 1);
}

void put() {
  int no;
  cin >> t >> no;
  fr[t] += no;
  update(1, MX, ROOT);
}

int rgnchk(int st, int en, int cur) {
  if(j < st || en < i) return 0;
  if(i <= st && en <= j) return frs[cur];
  int mid = (st + en) / 2;
  return update(st, mid, cur*2)
      + update(mid + 1, en, cur*2 + 1);
}

void pop() {
  int st = 1, en = MX, tar;
  cin >> tar;

  while(st != en) {
    int mid = (st + en) / 2;
    i = 1, j = mid;
    int cnt = rgnchk(1, MX, ROOT);
    if(cnt > tar) en = mid - 1;
    else st = mid;
  }
  cout << st << '\n';
  fr[st]--; t = st;
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

  i = 1, j = 1;
  cout << rgnchk(1, MX, ROOT) << '\n';
  i = 2, j = 2;
  cout << rgnchk(1, MX, ROOT) << '\n';
  i = 3, j = 3;
  cout << rgnchk(1, MX, ROOT) << '\n';
}