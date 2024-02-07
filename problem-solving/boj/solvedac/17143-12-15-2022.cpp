#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int board[102][102], tmp[102][102];
int r, c, m, sum;

struct shark { int x, y, sp, dir, sz; };

bool cmp(shark a, shark b) { return a.sz < b.sz; }
vector<shark> sh;

void init() {
  shark s; s.sz = 0; // 0th shark with size 0
  sh.push_back(s);
  
  for(int i = 0; i < m; i++) {
    int x, y, sp, dir, sz;
    cin >> x >> y >> sp >> dir >> sz;
    x--; y--; dir--;

    tie(s.x, s.y, s.sp, s.dir, s.sz) = {x, y, sp, dir, sz};
    sh.push_back(s);
  }
  sort(sh.begin(), sh.end(), cmp);

  for(int id = 1; id < sh.size(); id++) {
    shark &s = sh[id];
    board[s.x][s.y] = id;
  }
}

void catchShark(int ccol) {
  for(int i = 0; i < r; i++) {
    if(!board[i][ccol]) continue;
    int &id = board[i][ccol];
    sum += sh[id].sz;
    id = 0;
    return;
  }
}

pair<int, int> getnxdir(int cx, int dir, int sp) {
  int id = cx + sp * dx[dir];
  if(0 <= id && id < r) return {id, dir};
  id = abs(id) - 1;
  id %= 2*(r - 1);

  if(id < r - 1) return {id + 1, 1};
  else return {2*(r - 1) - 1 - id, 0};
}

pair<int, int> getnydir(int cy, int dir, int sp) {
  int id = cy + sp * dy[dir];
  if(0 <= id && id < c) return {id, dir};
  id = abs(id) - 1;
  id %= 2*(c - 1);

  if(id < c - 1) return {id + 1, 2};
  else return {2*(c - 1) - 1 - id, 3};
}

void move(int &id) {
  auto &s = sh[id];
  int cx, cy, sp, dir;
  tie(cx, cy, sp, dir) = {s.x, s.y, s.sp, s.dir};

  int nx = cx, ny = cy;
  if(sp != 0) {
    if(dir < 2) tie(nx, dir) = getnxdir(cx, dir, sp);
    else tie(ny, dir) = getnydir(cy, dir, sp);
  }
  tie(s.x, s.y, s.dir) = {nx, ny, dir};
  tmp[nx][ny] = max(tmp[nx][ny], id);
}

void moveShark() {
  for(int i = 0; i < r; i++)
    fill(tmp[i], tmp[i] + c, 0);
  
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++) {
      if(!board[i][j]) continue;
      move(board[i][j]);
    }

  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      board[i][j] = tmp[i][j];
}

void printboard() {
  cout << '\n';
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      cout << sh[board[i][j]].sz << " \n"[j + 1 == c];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c >> m;
  init();

  for(int i = 0; i < c; i++) {
    catchShark(i);
    moveShark();
  }
  cout << sum;
}