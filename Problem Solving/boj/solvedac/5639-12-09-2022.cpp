#include <bits/stdc++.h>
using namespace std;

const int MX = 10'002;
const int ROOT = 0;

int v[MX], lc[MX], rc[MX];
int unused = 1;

void insert(int cur) {
  int chk = ROOT, tmp;
  while(1) {
    if(v[chk] > v[cur]) tmp = lc[chk]; 
    else tmp = rc[chk];
    if(tmp == -1) break;
    chk = tmp;
  }
  if(v[chk] > v[cur]) lc[chk] = cur;
  else rc[chk] = cur;
}

void trav(int cur) {
  if(lc[cur] != -1) trav(lc[cur]);
  if(rc[cur] != -1) trav(rc[cur]);
  cout << v[cur] << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(lc, lc + MX, -1);
  fill(rc, rc + MX, -1);

  int x; cin >> x;
  v[ROOT] = x;

  while(cin >> x) {
    v[unused] = x;
    insert(unused);
    unused++;
  }
  trav(ROOT);
}