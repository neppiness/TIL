#include <bits/stdc++.h>
using namespace std;

const string boj = "BOJ";
const int inf = 0x7f7f7f7f;

int n; string s;
int cache[1002];

int solve(int idx) { // solve는 idx에서부터 n - 1까지 가는 데 드는 최소비용
  if (idx == n - 1) return 0;
  int &ret = cache[idx];
  if (ret != -1) return ret;

  int nxt = (boj.find(s[idx]) + 1) % 3;
  char nxt_char = boj[nxt];
  
  ret = inf;
  int pos = s.find(nxt_char, idx);
  while (pos != -1) {
    ret = min(ret, (pos - idx) * (pos - idx) + solve(pos));
    pos = s.find(nxt_char, pos + 1);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));
  cin >> n >> s;

  int ans = solve(0);
  if (ans == inf) ans = -1;
  cout << ans;
}