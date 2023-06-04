#include <bits/stdc++.h>
using namespace std;

const int kInf = 0x7f7f7f7f;

int c, n;
int cache[1002];
pair<int, int> ad[22];

int Solve(int x) {
  if (x >= c) { return 0; }

  int &ret = cache[x];
  if (ret != -1) return ret;

  ret = kInf;
  for (int i = 0; i < n; i++) {
    auto [co, no] = ad[i];
    ret = min(ret, co + Solve(x + no));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> c >> n;
  for (int i = 0; i < n; i++) {
    int co, no;
    cin >> co >> no;
    ad[i] = {co, no};
  }
  cout << Solve(0);
}