#include <bits/stdc++.h>
using namespace std;

int n; 
int dp[1002];
const string SKCY[] = {"CY", "SK"};

// solve: 상근이가 이길 수 있다면 1을, 진다면 0을 반환
// x: 이전에 창영이가 집은 돌이 몇 번째 돌인지
bool solve(int x) {
  if (x == n) return 1;
  int &ret = dp[x];
  if (ret != -1) return ret;

  // 상근이의 돌 선택
  for (int i : {x + 1, x + 3, x + 4}) {
    if (i >= n) continue;
    // 창영이의 돌 선택
    bool is_sk_win = 1;
    for (int j : {i + 1, i + 3, i + 4}) {
      if (j > n) continue;
      if (!solve(j)) is_sk_win = 0;
    }
    if (is_sk_win) return ret = 1;
  }
  return ret = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  bool sk_win = solve(0);
  cout << SKCY[sk_win];
}
