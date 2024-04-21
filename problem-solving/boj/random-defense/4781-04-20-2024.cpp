#include <bits/stdc++.h>
using namespace std;

pair<int, int> pr[5002];
int dp[10002];

int n, m;
string s;

int to_int(string &str) {
  int idx = str.find(".");
  
  string ss1 = str.substr(0, idx);
  string ss2 = str.substr(idx + 1);

  int a = stoi(ss1) * 100;
  int b = stoi(ss2);

  return a + b;
}

int solve(int x) {
  int &ret = dp[x];
  if (ret != -1) return ret;

  ret = 0;
  for (int i = 0; i < n; i++) {
    auto [c, p] = pr[i];
    if (x - p < 0) continue;
    ret = max(ret, c + solve(x - p));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  while (n != 0) {
    m = to_int(s);
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
      int c; string p_str;
      cin >> c >> p_str;
      int p = to_int(p_str);
      pr[i] = {c, p};
    }

    cout << solve(m) << '\n';
    cin >> n >> s;
  }
}
