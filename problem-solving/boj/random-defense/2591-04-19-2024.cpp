#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 34;

string s; 
int n, dp[40];

int solve(int idx) {
  if (idx == n) return 1;
  int &ret = dp[idx];
  if (ret != -1) return ret;

  ret = 0;
  if (s[idx] == '0') {
    return ret;
  }
  ret = solve(idx + 1);
  if (idx + 2 > n) {
    return ret;
  }
  string ss = s.substr(idx, 2);
  int x = stoi(ss);
  if (x <= LIMIT) {
    ret += solve(idx + 2);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> s;
  n = s.size();
  cout << solve(0);
}
