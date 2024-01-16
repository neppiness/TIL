#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int sum(int st, int en) {
  int sum_en = en * (en + 1) / 2;
  int sum_st = st * (st - 1) / 2;
  return sum_en - sum_st;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = INF;
  int n, k; cin >> n >> k;
  for (int st = 1; 1; st++) {
    int en = st + k - 1;
    int ps = sum(st, en);
    if (ps > n) break;
    int rest = n - ps;
    if (rest == 0) {
      ans = min(ans, en - st);
    } else if(rest < k) {
      ans = min(ans, en - st + 1);
    }
  }

  if (ans == INF) cout << -1;
  else cout << ans;
}
