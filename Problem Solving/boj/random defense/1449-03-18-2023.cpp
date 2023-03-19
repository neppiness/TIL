#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;

int cache[MX + 2][MX + 2];
int n, len;
vector<int> a;

int solve(int st, int en) {
  if(st == en) return 1;

  int &ret = cache[st][en];
  if(ret != -1) return ret;

  int x = (a[en] - a[st] + 1);
  ret = x / len + (x % len != 0);

  for(int mid = st; mid < en; mid++)
    ret = min(ret, solve(st, mid) + solve(mid + 1, en));
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n >> len;
  a.resize(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  cout << solve(0, n - 1);
}