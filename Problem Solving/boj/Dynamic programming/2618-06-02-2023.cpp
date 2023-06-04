#include <bits/stdc++.h>
using namespace std;

const int inf = 0x7f7f7f7f;

int sz, n; // sz: board size, n: no_of_case

// cache[i][j]: 1번째 차가 i번 사건, 2번째 차가 j번 사건을 해결한 시점에서
// 마지막 사건까지 해결할 때 거리 합의 최솟값
int cache[1002][1002];
pair<int, int> case_pos[1002];

int dist(int cur, int nxt, bool is_second_car) {
  int nx = case_pos[nxt].first;
  int ny = case_pos[nxt].second;
  int cx = 0, cy = 0;
  if (cur != 0) {
    cx = case_pos[cur].first;
    cy = case_pos[cur].second;
  } else if (is_second_car) {
    cx = sz - 1; cy = sz - 1;
  }
  return abs(nx - cx) + abs(ny - cy);
}

int solve(int i, int j) {
  int &ret = cache[i][j];
  if (ret != -1) return ret;

  int nxt = max(i, j) + 1;
  if (nxt == n + 1) return ret = 0;
  
  int tmp[2] = {};
  tmp[0] = dist(i, nxt, 0) + solve(nxt, j); // 1번차가 nxt 사건을 맡음
  tmp[1] = dist(j, nxt, 1) + solve(i, nxt); // 2번차가 nxt 사건을 맡음
  return ret = min(tmp[0], tmp[1]);
}

void trace(int i, int j) {
  int nxt = max(i, j) + 1;
  if (nxt == n + 1) return;

  int tmp[2] = {};
  tmp[0] = dist(i, nxt, 0) + solve(nxt, j); // 1번차가 nxt 사건을 맡음
  tmp[1] = dist(j, nxt, 1) + solve(i, nxt); // 2번차가 nxt 사건을 맡음
  if (tmp[0] < tmp[1]) {
    cout << 1 << '\n';
    trace(nxt, j);
  } else {
    cout << 2 << '\n';
    trace(i, nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  memset(cache, -1, sizeof(cache));

  cin >> sz >> n;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    case_pos[i] = {x - 1, y - 1};
  }
  cout << solve(0, 0) << '\n';
  trace(0, 0);
}