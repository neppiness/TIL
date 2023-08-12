#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e6;

int dp[1002][3][4];

int solve(int day) {

  dp[1][0][0] = 1; // O
  dp[1][1][0] = 1; // L
  dp[1][0][1] = 1; // A

  for (int i = 1; i < day; i++) {
    // O를 붙이는 경우, late는 유지
    for (int late = 0; late <= 1; late++) {
      for (int ab = 0; ab <= 2; ab++) {
        int &res = dp[i + 1][late][0]; // 지각 수 유지, 결석 스택 끊김
        res += dp[i][late][ab]; // 결석이 몇 스택이든 상관 없이 O를 붙일 수 있다.
        if (res >= kMod) res -= kMod;
      }
    }

    // L을 붙이는 경우, late 증가
    for (int ab = 0; ab <= 2; ab++) {
      int &res = dp[i + 1][1][0]; // 지각 수 증가, 결석 스택 끊김, 결석 스택 끊김
      res += dp[i][0][ab]; // 결석이 몇 스택이든 상관 없이 L을 붙일 수 있음.
      if (res >= kMod) res -= kMod;
    }

    // A를 붙이는 경우
    for (int late = 0; late <= 1; late++) {
      for (int ab = 0; ab < 2; ab++) {
        int &res = dp[i + 1][late][ab + 1]; // 지각 수 유지, 결석 스택 증가
        res += dp[i][late][ab]; // 결석은 현 상태의 하나 전 상태여야 함.
        if (res >= kMod) res -= kMod;
      }
    }
  }

  int ans = 0;
  for (int late = 0; late <= 1; late++) {
    for (int ab = 0; ab <= 2; ab++) {
      ans += dp[day][late][ab];
      if (ans >= kMod) ans -= kMod;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cout << solve(n);
}