#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pts;
int b[9][9];

bool row[9][10], col[9][10];
bool thrxthr[3][3][10];
bool isSolved;

void init() {
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++) {
      int x; cin >> x;
      if(!x) {
        pts.push_back({i, j});
        continue;
      }
      b[i][j] = x;
      row[i][x] = 1; col[j][x] = 1;
      thrxthr[i/3][j/3][x] = 1;
    }
}

void setno(int x, int y, int no, bool code) {
  b[x][y] = no * code;
  row[x][no] = col[y][no] = code;
  thrxthr[x/3][y/3][no] = code;
}

void print() {
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      cout << b[i][j] << " \n"[j + 1 == 9];
}

void solve(int lv) {
  if(lv == pts.size()) {
    isSolved = true;
    print();
    return;
  }
  auto [x, y] = pts[lv];
  for(int no = 1; no <= 9; no++) {
    if(row[x][no] || col[y][no]) continue;
    if(thrxthr[x/3][y/3][no]) continue;
    setno(x, y, no, 1);
    solve(lv + 1);
    if(isSolved) return;
    setno(x, y, no, 0);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  init();
  solve(0);
}