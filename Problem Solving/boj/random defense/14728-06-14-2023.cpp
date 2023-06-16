#include <bits/stdc++.h>
using namespace std;

int n, t;
int cache[102][10002];
int k[102], s[102];

int solve(int no, int time) { // no번 단원 선택할 때 time시간을 사용했다면-
  int &ret = cache[no][time];
  if (no == n) return ret = 0;
  if (ret != -1) return ret;

  ret = solve(no + 1, time);
  if (time + k[no] <= t)
    ret = max(ret, solve(no + 1, time + k[no]) + s[no]);
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n >> t;
  for (int i = 0; i < n; i++)
    cin >> k[i] >> s[i];
  cout << solve(0, 0); // 0번 단원 선택 여부 결정, 0시간 사용함
}