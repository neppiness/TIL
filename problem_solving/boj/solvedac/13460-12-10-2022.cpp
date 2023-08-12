#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int cnt = INF;

struct Board {
  char b[12][12];
  int rlim, clim;
  bool isRedEscaped, isBlueEscaped;
};

// left (<-) dir. move
void move(Board &bo) {
  for(int i = 0; i < bo.rlim; i++)
    for(int j = 0; j < bo.clim; j++) {
      bool isHole; int movable;
      char &c = bo.b[i][j];
      if(c == '#') {
        movable = -1;
        isHole = 0;
      } else if(c == 'O') {
        if(movable == -1) movable = j;
        isHole = 1;
      } else if(c == 'R' || c == 'B') {
        if(movable == -1) continue;
        else {
          if(isHole) {
            if(c == 'R') bo.isRedEscaped = 1;
            else bo.isBlueEscaped = 1;
            c = '.';
          } else swap(c, bo.b[i][movable]);
        }
        j = movable;
        movable = -1;
      } else if(c == '.' && movable == -1) movable = j;
    }
}

Board rotate(Board bo) {
  char tmp[12][12];

  for(int i = 0; i < bo.rlim; i++)
    for(int j = 0; j < bo.clim; j++)
      tmp[j][bo.rlim - i - 1] = bo.b[i][j];

  swap(bo.rlim, bo.clim);

  for(int i = 0; i < bo.rlim; i++)
    for(int j = 0; j < bo.clim; j++)
      bo.b[i][j] = tmp[i][j];
  return bo;
}

bool isEscaped(Board &bo, int lv) {
  if(bo.isRedEscaped && !bo.isBlueEscaped)
    cnt = min(cnt, lv + 1);
  return (bo.isRedEscaped || bo.isBlueEscaped);
}

void solve(Board bo, int lv) {
  if(lv == 10) return;

  vector<Board> rBoards;
  rBoards.push_back(bo);
  for(int ro = 0; ro < 3; ro++)
    rBoards.push_back(rotate(rBoards[ro]));
  
  for(int i = 0; i < 4; i++) {
    rBoards[i].isRedEscaped = 0;
    rBoards[i].isBlueEscaped = 0;
  }

  for(int i = 0; i < 4; i++) {
    Board &rb = rBoards[i];
    move(rb);
    if(isEscaped(rb, lv)) continue;
    solve(rb, lv + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  Board board;
  cin >> board.rlim >> board.clim;

  for(int i = 0; i < board.rlim; i++)
    for(int j = 0; j < board.clim; j++)
      cin >> board.b[i][j];

  solve(board, 0);

  if(cnt == INF) cnt = -1;
  cout << cnt;
}