#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1e+9;
const int MX = 100 + 2;

ll cache[MX][10][10];
int d[] = {-1, 1};

bool oor(int x) { return (x < 0 || x > 9); }

ll solve(int len, int st, int en) {
  ll &ret = cache[len][st][en];
  if(ret != -1) return ret;
  if(len <= 10) return ret = 0;

  ret = 0;
  for(int dir = 0; dir < 2; dir++) {
    int nst = st + d[dir];
    int nen = en + d[dir];
    if(!oor(nst)) {
      ret += solve(len - 1, nst, en);
      if(ret >= M) ret -= M;
    }
    if(!oor(nen)) {
      ret += solve(len - 1, st, nen);
      if(ret >= M) ret -= M;
    }
  }
  ret += solve(len - 2, st, en) * (len - 3)*2;
  if(ret >= M) ret -= M;
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  memset(cache, -1, sizeof(cache));
  // base case setting
  cache[10][9][0] = 1;
  cache[10][0][9] = 1;

  ll ans = 0;
  for(int st = 1; st <= 9; st++)
    for(int en = 0; en <= 9; en++) {
      ans += solve(n, st, en);
      if(ans >= M) ans -= M;
    }
  cout << ans;
  
  ll tmp = 0;
  for(int st = 1; st <= 9; st++)
    for(int en = 0; en <= 9; en++)
      for(int k = 1; k <= 40; k++)
        tmp += solve(k, st, en);

  cout << tmp;
}