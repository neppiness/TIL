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
  int nx;
  if(dir == 1) nx = cx + sp * dx[dir] - 1;
  else nx = r - cx + sp * dx[dir];

  int rlim = (r - 1) * 2;
  nx = ((nx % rlim) + rlim) % rlim;

  dir = (r - 1 > nx);
  if(nx >= r - 1) nx = rlim - nx - 1;
  else nx++;
  return {nx, dir};
}

pair<int, int> getnydir(int cy, int dir, int sp) {
  int ny;
  if(dir == 2) ny = cy + sp * dy[dir] - 1;
  else ny = 2 * (c - 1) - 1 - cy + sp * dy[dir];

  int clim = (c - 1) * 2;
  ny = ((ny % clim) + clim) % clim;

  dir = 2 + (ny >= c - 1);
  if(ny >= c - 1) ny = clim - 1 - ny;
  else ny++;
  return {ny, dir};
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

void test() {
  for(int i = 0; i <= 12; i++) {
    auto [ny, dir] = getnydir(0, 3, i);
    cout << ny << ' ' << dir << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c >> m;
  init();

  test();
  return 0;

  cout << "초기 상태\n";
  printboard();

  for(int i = 0; i < c; i++) {
    cout << '\n' << i + 1 << "초후\n";
    catchShark(i);
    cout << "\n상어 잡혀감\n";
    printboard();
    cout << "\n상어 움직임\n";
    moveShark();
    printboard();
  }
  cout << sum;
}
// Need to debug