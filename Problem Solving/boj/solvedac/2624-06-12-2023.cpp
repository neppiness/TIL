#include <bits/stdc++.h>
using namespace std;

int t, k;
int cache[102][10'002];
int p[102], n[102];

int solve(int cur_k, int cur_t) {
  if (cur_t == 0) return 1;
  if (cur_k < 0) return 0;

  int &ret = cache[cur_k][cur_t];
  if (ret != -1) return ret;

  ret = 0;
  for (int i = 0; i <= n[cur_k]; i++) {
    int nxt_t = cur_t - p[cur_k] * i;
    if (nxt_t < 0) break;
    ret += solve(cur_k - 1, nxt_t);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> t >> k;
  for (int i = 0; i < k; i++)
    cin >> p[i] >> n[i];
    
  cout << solve(k - 1, t);
}