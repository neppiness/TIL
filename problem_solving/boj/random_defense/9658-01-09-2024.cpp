#include <bits/stdc++.h>
using namespace std;

const string SKCY[] = {"SK", "CY"};
bool dp[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    for (int j : {i - 1, i - 3, i - 4}) {
      if (j < 0) continue;
      dp[i] |= !dp[j];
    }
  }

  bool is_sk_win = 1;
  for (int i : {n - 1, n - 3, n - 4}) {
    if (i < 0) continue;
    is_sk_win &= !dp[i];
  }
  cout << SKCY[is_sk_win];
}
