#include <bits/stdc++.h>
using namespace std;

int ans;
string s;
int dp[502][502];

bool isAtOrGc(int st, int en) {
  if (s[st] == 'a' && s[en] == 't') return 1;
  return s[st] == 'g' && s[en] == 'c';
}

bool solve(int st, int en) {
  int len = en - st + 1;
  if (len <= 1) return 0;
  if (len == 2) {
    if (!isAtOrGc(st, en)) return 0;
    ans = max(ans, len);
    return 1;
  }

  int &ret = dp[st][en];
  if (ret != -1) return ret;

  if (!isAtOrGc(st, en)) return ret = 0;

  for (int mid = st; mid <= en; mid++) {
    if (!solve(st, mid) || !solve(mid, en)) continue;
    ans = max(ans, len);
    return ret = 1;
  }
  return ret = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  memset(dp, -1, sizeof(dp));

  cin >> s;

  int n = s.size();
  for (int st = 0; st < n; st++)
    for (int en = st; en < n; en++)
      solve(st, en);

  cout << ans; 
}
// 풀이가 틀렸음. a, t, g, c일 때만 확인해야하는 게 아님.
// 풀이 구상을 아예 다시해보자.
