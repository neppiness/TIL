#include <bits/stdc++.h>
using namespace std;

string b[2], e;
int cache[2][20][102];

int solve(bool is_angel, int cur_e, int st) {
  if (cur_e == e.size()) return 1;

  int &ret = cache[is_angel][cur_e][st];
  if (ret != -1) return ret;
  ret = 0;

  int pos = b[!is_angel].find(e[cur_e], st + 1);
  while (pos != -1) {
    ret += solve(!is_angel, cur_e + 1, pos);
    pos =  b[!is_angel].find(e[cur_e], pos + 1);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> e >> b[0] >> b[1];
  
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    int pos = b[i].find(e[0]);
    while (pos != -1) {
      ans += solve((i == 1), 1, pos);
      pos = b[i].find(e[0], pos + 1);
    }
  }
  cout << ans;
}