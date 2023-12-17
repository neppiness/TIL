#include <bits/stdc++.h>
using namespace std;

string b[37];
bool vis[6][6];

bool solve() {
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      if (!vis[i][j]) return 0;

  for (int i = 0; i < 36; i++) {
    int j = (i + 1) % 36;
    int drow = abs(b[i][1] - b[j][1]);
    int dcol = abs(b[i][0] - b[j][0]);
    if ((drow == 2 && dcol == 1) || (drow == 1 && dcol == 2))
      continue;
    return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 36; i++) {
    cin >> b[i];
    int col = b[i][0] - 'A';
    int row = b[i][1] - '1';
    vis[row][col] = 1;
  }

  string pr[] = {"Invalid", "Valid"};
  cout << pr[solve()];
}
