#include <bits/stdc++.h>
using namespace std;

bool at_row[52];
bool at_col[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      if (c == '.') continue;
      at_row[i] = 1;
      at_col[j] = 1;
    }
  }

  int row_cnt = 0, col_cnt = 0;
  for (int i = 0; i < n; i++)
    row_cnt += !at_row[i];
  for (int j = 0; j < m; j++)
    col_cnt += !at_col[j];

  cout << max(row_cnt, col_cnt);
}
