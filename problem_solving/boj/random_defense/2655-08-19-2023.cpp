#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int, int, int, int>> b; // block = {area, height, weight, no} 
int dp[102][102];
pair<int, int> memo[1'000'002];

int solve(int x, int idx) { // x번째 아래에 깔리는 블록이 밑면의 넓이가 idx번째인 블록이면 아래에 둘 수 있는 최대 높이
  int &ret = dp[x][idx];
  if (ret != -1) return ret;
  
  auto [a, h, w, no] = b[idx]; 
  ret = h;
  for (int i = idx + 1; i < n; i++) {
    auto [na, nh, nw, nno] = b[i];
    if (w >= nw) continue;
    if (ret > h + solve(x + 1, i)) continue;
    ret = h + solve(x + 1, i); 
    memo[ret] = {x, idx};
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, h, w; cin >> a >> h >> w;
    b.push_back({a, h, w, i}); 
  }
  sort(b.begin(), b.end());  
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, solve(1, i));
  } 
  cout << ans;
}
