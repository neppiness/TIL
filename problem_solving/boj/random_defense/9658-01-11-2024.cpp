#include <bits/stdc++.h>
using namespace std;

int n; 
int dp[1002];
const string SKCY[] = {"CY", "SK"};

bool solve(int x) {
  if (x == n) return 0;
  int &ret = dp[x];
  if (ret != -1) return ret;
  // 창영이의 돌 선택
  for (int i : {x + 1, x + 3, x + 4}) {
    if (i + 1 > n) continue;
    if (!solve(i + 1)) return ret = 0;
  }
  return ret = 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  bool sk_win = 0;
  for (int i : {1, 3, 4}) {
    if (i > n) continue;
    sk_win |= solve(i);
  }
  cout << SKCY[sk_win];
}
