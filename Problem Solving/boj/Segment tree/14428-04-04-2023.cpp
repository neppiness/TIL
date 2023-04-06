#include <bits/stdc++.h>
using namespace std;

const int MX = 100'002;
const int ROOT = 1;
const int INF = 0x3f3f3f3f;

int n, m, i, j;
pair<int, int> mn[4*MX];
int a[MX];

pair<int, int> init(int st, int en, int cur) {
  if(st == en) return mn[cur] = {a[st], st};
  int mid = (st + en) / 2;
  return mn[cur] = min(init(st, mid, cur*2), init(mid + 1, en, cur*2 + 1));
}

pair<int, int> update(int st, int en, int cur) {
  if(en < i || i < st) return mn[cur];
  if(st == en) return mn[cur] = {a[st], st};
  int mid = (st + en) / 2;
  return mn[cur] = min(update(st, mid, cur*2), update(mid + 1, en, cur*2 + 1));
}

pair<int, int> query(int st, int en, int cur) {
  if(en < i || j < st) return {INF, INF};
  if(i <= st && en <= j) return mn[cur];
  int mid = (st + en) / 2;
  return min(query(st, mid, cur*2), query(mid + 1, en, cur*2 + 1));
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
    int code; cin >> code;
    if(code == 1) {
      cin >> i >> a[i];
      update(1, n, ROOT);
    } else {
      cin >> i >> j;
      cout << query(1, n, ROOT).second << '\n';
    }
  }
}