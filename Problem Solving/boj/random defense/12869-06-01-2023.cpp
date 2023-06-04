#include <bits/stdc++.h>
using namespace std;

int n, cache[62][62][62];

int solve(int a, int b, int c) {
  vector<int> v = {a, b, c};
  sort(v.begin(), v.end());

  for (int &x : v)
    if (x < 0) x = 0;

  int &ret = cache[v[0]][v[1]][v[2]];
  if (ret != -1) return ret;
  if (v[0] == 0 && v[1] == 0 && v[2] == 0)
    return ret = 0;

  ret = 0x7f7f7f7f;
  ret = min(ret, 1 + solve(v[0] - 9, v[1] - 3, v[2] - 1));
  ret = min(ret, 1 + solve(v[0] - 9, v[1] - 1, v[2] - 3));
  ret = min(ret, 1 + solve(v[0] - 3, v[1] - 9, v[2] - 1));
  ret = min(ret, 1 + solve(v[0] - 1, v[1] - 9, v[2] - 3));
  ret = min(ret, 1 + solve(v[0] - 1, v[1] - 3, v[2] - 9));
  ret = min(ret, 1 + solve(v[0] - 3, v[1] - 1, v[2] - 9));
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  vector<int> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    v.push_back(x);
  }

  for (int i = n; i <= 3; i++)
    v.push_back(0);

  cout << solve(v[0], v[1], v[2]);
}