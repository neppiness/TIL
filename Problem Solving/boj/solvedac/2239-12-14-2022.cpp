#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pos;
string board[9];

bool isUsed[3][3][10];
bool row[9][10], col[9][10];
bool isSolved;

void setup(int x, int y, bool code, int no) {
  isUsed[x / 3][y / 3][no] = code;
  row[x][no] = code;
  col[y][no] = code;
  board[x][y] = '0' + code * no;
}

void solve(int lv) {
  if(lv == pos.size()) {
    isSolved = 1;
    return;
  }
  auto [cx, cy] = pos[lv];
  for(int no = 1; no <= 9; no++) {
    if(isUsed[cx / 3][cy / 3][no]) continue;
    if(row[cx][no]) continue;
    if(col[cy][no]) continue;
    setup(cx, cy, 1, no);
    solve(lv + 1);
    if(isSolved) return;
    setup(cx, cy, 0, no);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // setup
  for(int i = 0; i < 9; i++) {
    cin >> board[i];
    for(int j = 0; j < 9; j++) {
      int x = board[i][j] - '0';
      if(x == 0) {
        pos.push_back({i, j});
        continue;
      }
      isUsed[i / 3][j / 3][x] = 1;
      row[i][x] = 1;
      col[j][x] = 1;
    }
  }
  solve(0);

  for(int i = 0; i < 9; i++)
      cout << board[i] << '\n';
}