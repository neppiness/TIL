#include <bits/stdc++.h>
using namespace std;

int b[5][5];
bool is_checked[5][5];

bool is_solved(int no) {
  int x, y;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      if (b[i][j] == no) tie(x, y) = {i, j};
  is_checked[x][y] = 1;

  int cnt = 0;
  
  for (int i = 0; i < 5; i++) {
    bool is_completed = 1;
    for (int j = 0; j < 5; j++)
      is_completed &= is_checked[i][j];
    cnt += is_completed;
  }

  for (int j = 0; j < 5; j++) {
    bool is_completed = 1;
    for (int i = 0; i < 5; i++)
      is_completed &= is_checked[i][j];
    cnt += is_completed;
  }

  bool is_completed = 1;
  for (int i = 0; i < 5; i++)
    is_completed &= is_checked[i][i];
  cnt += is_completed;

  is_completed = 1;
  for (int i = 0; i < 5; i++)
    is_completed &= is_checked[i][4 - i];
  cnt += is_completed;
  return cnt >= 3;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      cin >> b[i][j];

  int ans = 25;
  for (int i = 1; i <= 25; i++) {
    int no; cin >> no;
    if (is_solved(no)) ans = min(ans, i);
  }
  cout << ans;
}
