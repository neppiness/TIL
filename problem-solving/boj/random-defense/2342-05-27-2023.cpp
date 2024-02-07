#include <bits/stdc++.h>
using namespace std;

const int inf = 0x7f7f7f7f;
int n;
int a[100'002];
int cache[5][5][100'002]; // cache[왼발][오른발][패턴]

int solve(int lf, int rf, int idx) {
  if (idx == n) { return 0; }
  int &ret = cache[lf][rf][idx];
  if (ret != -1) return ret;
  ret = inf;

  // 왼발을 움직이는 경우
  int cost = 0;
  if (lf == 0) {
    cost = 2;
  } else {
    int val = abs(a[idx] - lf);
    if (val == 0) cost = 1;
    else if (val == 2) cost = 4;
    else cost = 3;
  }
  ret = min(ret, cost + solve(a[idx], rf, idx + 1));

  // 오른발을 움직이는 경우
  if (rf == 0) {
    cost = 2;
  } else {
    int val = abs(a[idx] - rf);
    if (val == 0) cost = 1;
    else if (val == 2) cost = 4;
    else cost = 3;
  }
  ret = min(ret, cost + solve(lf, a[idx], idx + 1));
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x; cin >> x;
  while (x != 0) {
    a[n++] = x;
    cin >> x;
  }

  memset(cache, -1, sizeof(cache));
  cout << solve(0, 0, 0);
}