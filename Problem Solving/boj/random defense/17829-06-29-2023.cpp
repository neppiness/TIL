#include <bits/stdc++.h>
using namespace std;

int n, b[1024][1024];

int solve(int x, int y, int len) {
  if (len == 1) {
    int a[] = {b[x][y], b[x][y + len], b[x + len][y], b[x + len][y + len]};
    sort(a, a + 4);
    return a[2];
  }

  int dl = len / 2;
  vector<int> a;
  a.push_back(solve(x, y, dl));
  a.push_back(solve(x + dl + 1, y, dl));
  a.push_back(solve(x, y + dl + 1, dl));
  a.push_back(solve(x + dl + 1, y + dl + 1, dl));
  sort(a.begin(), a.end());
  return a[2];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> b[i][j];

  cout << solve(0, 0, n - 1);
}