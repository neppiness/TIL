#include <bits/stdc++.h>
using namespace std;

priority_queue< tuple<int, int, int, int>,
    vector<tuple<int, int, int, int>>,
    greater<tuple<int, int, int, int>> > pq; // {거울 사용 횟수, x좌표, y좌표, 방향}

int n;
char b[52][52];
int refl[52][52][5]; // refl는 반사 횟수다. 인덱스는 x좌표, y좌표, 현 방향.

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int mrid[52][52], mrcnt = 1;
vector<pair<int, int>> door;

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= n || y < 0;
}

bool needCheck(int x, int y, int dir, int comp) {
  return refl[x][y][dir] == -1 || refl[x][y][dir] < comp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(refl, -1, sizeof(refl));

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
      if (b[i][j] == '!') {
        mrid[i][j] = mrcnt++;
      } else if (b[i][j] == '#') {
        door.push_back({i, j});
      }
    }
  }
  
  for (int dir = 0; dir < 4; dir++) {
    auto [x, y] = door[0];
    pq.push({0, x, y, dir});
    refl[x][y][dir] = 0;
  }

  auto [tx, ty] = door[1];
  while (!pq.empty()) {
    auto [cnt, cx, cy, dir] = pq.top(); pq.pop();
    if (refl[cx][cy][dir] != cnt) continue;
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if (oob(nx, ny) || b[nx][ny] == '*') continue;
    if (!needCheck(nx, ny, dir, cnt)) continue;
    if (nx == tx && ny == ty) { cout << cnt; return 0; }
    if (mrid[nx][ny]) { // 거울이 있는 위치라면
      for (int ddir : {1, 3}) {
        int ndir = (dir + ddir) % 4;
        if (!needCheck(nx, ny, ndir, cnt + 1)) continue;
        pq.push({cnt + 1, nx, ny, ndir});
        refl[nx][ny][ndir] = cnt + 1;
      }
    }
    refl[nx][ny][dir] = cnt;
    pq.push({cnt, nx, ny, dir});
  }
}