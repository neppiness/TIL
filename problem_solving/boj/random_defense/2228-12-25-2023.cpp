#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int n, m;
int ps[102]; // ps: a_i번까지 부분합
int dp[102][102][52];

int solve(int st, int en, int no) {
  int &ret = dp[st][en][no];
  if (ret != INF) return ret;
  if (no == 1) {
    return ret = ps[en] - ps[st - 1];
  }
  ret = -INF;
  for (int mid = st; mid < en; mid++)
    ret = max(ret, ps[mid] - ps[st - 1] + solve(mid + 1, en, no - 1)); 
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, 0x7f, sizeof(dp));

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> ps[i];
    ps[i] += ps[i - 1];
  }
  cout << solve(1, n, m); // 0부터 n - 1까지 수를 m개 구간으로 나눈다.
}
