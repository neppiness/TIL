#include <bits/stdc++.h>
using namespace std;

string a, b, c;
int cache[102][102][102];
int ans = 0;

int solve(int aidx, int posb, int posc) {
  int &ret = cache[aidx][posb][posc];
  if (ret != -1) return ret;
  ret = 1;
  for (int i = aidx + 1; i < a.length(); i++) {
    int nposb = b.find(a[i], posb + 1);
    int nposc = c.find(a[i], posc + 1);
    if (nposb == -1 || nposc == -1) continue;
    ret = max(ret, solve(i, nposb, nposc) + 1);
  }
  return ret;
}

void solve() {
  for (int aidx = 0; aidx < a.length(); aidx++) {
    int posb = b.find(a[aidx]);
    int posc = c.find(a[aidx]);
    if (posb == -1 || posc == -1) continue;
    ans = max(ans, solve(aidx, posb, posc));
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));
  cin >> a >> b >> c;
  solve();
  cout << ans;
}