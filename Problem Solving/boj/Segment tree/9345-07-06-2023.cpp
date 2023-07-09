#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int ROOT = 1;

int n, k;
int x[100'002], mn[400'002], mx[400'002];

int mininit(int nlb, int nrb, int cur) {
  if (nlb == nrb) return mn[cur] = x[nlb];
  int nmid = (nlb + nrb) / 2;
  return mn[cur] = min(
      mininit(nlb, nmid, cur*2),
      mininit(nmid + 1, nrb, cur*2 + 1)
  );
}

int maxinit(int nlb, int nrb, int cur) {
  if (nlb == nrb) return mx[cur] = x[nlb];
  int nmid = (nlb + nrb) / 2;
  return mx[cur] = max(
      maxinit(nlb, nmid, cur*2),
      maxinit(nmid + 1, nrb, cur*2 + 1)
  );
}

int update(bool is_max, int tar, int nlb, int nrb, int cur) {
  if (tar < nlb || nrb < tar) {
    if (is_max) return mx[cur];
    return mn[cur];
  }
  if (nlb == nrb) {
    if (is_max) return mx[cur] = x[tar];
    return mn[cur] = x[tar];
  }

  int nmid = (nlb + nrb) / 2;
  if (is_max) {
    return mx[cur] = max(
        update(1, tar, nlb, nmid, cur*2),
        update(1, tar, nmid + 1, nrb, cur*2 + 1)
    );
  }
  return mn[cur] = min(
      update(0, tar, nlb, nmid, cur*2),
      update(0, tar, nmid + 1, nrb, cur*2 + 1)
  );
}

pair<int, int> getminmax(int qlb, int qrb, int nlb, int nrb, int cur) {
  if (qlb <= nlb && nrb <= qrb) return {mn[cur], mx[cur]};
  // 유효한 값이 0부터 n - 1까지기 때문에 inf, -inf와 다름 없다.
  if (nrb < qlb || qrb < nlb) return {n, -1};

  int nmid = (nlb + nrb) / 2;
  pair<int, int> ltpair = getminmax(qlb, qrb, nlb, nmid, cur*2);
  pair<int, int> rtpair = getminmax(qlb, qrb, nmid + 1, nrb, cur*2 + 1);
  return {min(ltpair.X, rtpair.X), max(ltpair.Y, rtpair.Y)};
}

void maxupdate(int idx) { update(1, idx, 0, n - 1, ROOT); }
void minupdate(int idx) { update(0, idx, 0, n - 1, ROOT); }

void swapval(int aidx, int bidx) {
  int aval = x[aidx], bval = x[bidx];
  x[aidx] = bval;
  maxupdate(aidx); minupdate(aidx);
  x[bidx] = aval;
  maxupdate(bidx); minupdate(bidx);
}

void init() {
  for (int i = 0; i < n; i++) x[i] = i;
  maxinit(0, n - 1, ROOT);
  mininit(0, n - 1, ROOT);
}

void check(int qlb, int qrb) {
  pair<int, int> ret = getminmax(qlb, qrb, 0, n - 1, ROOT);
  if (ret.X == qlb && ret.Y == qrb) cout << "YES\n";
  else cout << "NO\n";
}

void solve() {
  while (k--) {
    bool code; int a, b;
    cin >> code >> a >> b;
    if (code == 0) swapval(a, b);
    else check(a, b);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    cin >> n >> k;
    init();
    solve();
  }
}