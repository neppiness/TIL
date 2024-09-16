#include <bits/stdc++.h>
using namespace std;

const string pr[] = {"INCORRECT", "CORRECT"};

int r_cnt[10][10];
int c_cnt[10][10];
int t_cnt[3][3][10];

bool solve() {
  memset(r_cnt, 0, sizeof(r_cnt));
  memset(c_cnt, 0, sizeof(c_cnt));
  memset(t_cnt, 0, sizeof(t_cnt));

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int x; cin >> x;
      r_cnt[i][x]++; c_cnt[j][x]++;
      t_cnt[i / 3][j / 3][x]++;
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int x = 1; x <= 9; x++) {
      if (r_cnt[i][x] == 1) continue;
      return 0;
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int x = 1; x <= 9; x++) {
      if (c_cnt[i][x] == 1) continue;
      return 0;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int x = 1; x <= 9; x++) {
        if (t_cnt[i][j][x] == 1) continue;
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;
  for (int t = 1; t <= T; t++)
    cout << "Case " << t << ": " << pr[solve()] << '\n';
}
