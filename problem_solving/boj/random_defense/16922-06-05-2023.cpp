#include <bits/stdc++.h>
using namespace std;

bool can_be_made[20][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int x : {1, 5, 10, 50})
    can_be_made[0][x] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= 1000; j++) {
      if (!can_be_made[i - 1][j]) continue;
      for (int x : {1, 5, 10, 50})
        can_be_made[i][j + x] = 1;
    }
  }

  int cnt = 0;
  for (int j = 0; j <= 1000; j++)
    if (can_be_made[n - 1][j]) cnt++;
  cout << cnt;
}