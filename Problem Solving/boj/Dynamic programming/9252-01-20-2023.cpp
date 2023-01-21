#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;

string key, lck;
stack<char> st;
int cache[MX + 2][MX + 2];

int solve(int keyidx, int lckidx) {
  if(keyidx < 0 || lckidx < 0) return 0;
  int &ret = cache[keyidx][lckidx];
  if(ret != -1) return ret;

  ret = max(solve(keyidx - 1, lckidx), solve(keyidx, lckidx - 1));
  bool ismatched = (key[keyidx] == lck[lckidx]);
  return ret = max(ret, solve(keyidx - 1, lckidx - 1) + ismatched);
}

void print(int keyidx, int lckidx, int curlen) {
  bool ismatched = (key[keyidx] == lck[lckidx]);
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));
  cin >> key >> lck;

  int ans = solve(key.length() - 1, lck.length() - 1);
  cout << ans << '\n';
  cout << print(key.length() - 1, lck.length() - 1, ans) << '\n';
}