#include <bits/stdc++.h>
using namespace std;

int winner[1002]; // 0: CY, 1: SK

int solve(int x) {
  if (x <= 0) return 0;
  int &ret = winner[x];
  if (ret != -1) return ret;

  for (int dx : {1, 3, 4}) {
    int prv = x - dx;
    if (prv <= 0) continue;
    if (!solve(prv)) return ret = 1;
  }
  return ret = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(winner, -1, sizeof(winner));

  int n; cin >> n;

  if (solve(n - 1) || solve(n - 3) || solve(n - 4)) {
    cout << "SK"; return 0;
  }
  cout << "CY";
}