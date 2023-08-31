#include <bits/stdc++.h>
using namespace std;

bool is_rev;
int cnt;

int n, m, k, idx, sz;
int prv[5002];
int nxt[5002];
int val[5002];

void goKthElem(int d) {
  int *toGo = nxt;
  if (is_rev) toGo = prv;
  while (d--)
    idx = toGo[idx];
}

void delElem() {
  int pidx = prv[idx];
  int nidx = nxt[idx];
  nxt[pidx] = nidx;
  prv[nidx] = pidx;
  if (++cnt != m) return;
  cnt = 0;
  is_rev = !is_rev;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  memset(prv, -1, sizeof(prv));
  memset(nxt, -1, sizeof(nxt));

  cin >> n >> k >> m;
  sz = n;
  // node no. from 0 to n - 1
  for (int i = 0; i < n; i++) {
    val[i] = i + 1;
    nxt[i] = i + 1;
    prv[i + 1] = i;
  }
  prv[0] = n - 1;
  nxt[n - 1] = 0;

  idx = n - 1;
  while (sz) {
    goKthElem(k);
    delElem();
    cout << val[idx] << '\n';
    sz--;
  }
}
