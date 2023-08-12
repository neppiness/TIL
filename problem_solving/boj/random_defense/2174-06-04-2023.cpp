#include <bits/stdc++.h>
using namespace std;

// NESW, R: dir++ / L: dir--
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, r, c;
int b[102][102]; // [세로축(y)][가로축(x)]
tuple<int, int, int> robot[102]; // x, y, dir
tuple<int, char, int> command[102]; // robot_no, com, no_of_cycle

int GetDir(char c) {
  switch(c) {
    case 'N': return 0;
    case 'E': return 1;
    case 'S': return 2;
    default: return 3;
  }
}

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

int DoCommand(int com_idx) {
  auto [robot_no, com, no_of_cycle] = command[com_idx];
  auto [x, y, dir] = robot[robot_no];

  if (com == 'F') {
    int cx = x, cy = y;
    while (no_of_cycle--) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (OOB(nx, ny)) return 1;
      if (b[nx][ny]) return 2 + b[nx][ny];
      swap(nx, cx); swap(ny, cy);
    }
    b[x][y] = 0;
    b[cx][cy] = robot_no;
    robot[robot_no] = {cx, cy, dir};
  } else {
    if (com == 'L') dir -= no_of_cycle;
    if (com == 'R') dir += no_of_cycle;
    dir = ((dir % 4) + 4) % 4;
    robot[robot_no] = {x, y, dir};
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  cin >> r >> c;

  for (int i = 1; i <= r; i++) {
    int x, y; char dir;
    cin >> y >> x >> dir;
    robot[i] = {x - 1, y - 1, GetDir(dir)};
    b[x - 1][y - 1] = i;
  }

  for (int i = 0; i < c; i++) {
    int robot_no, no_of_cycle; char com;
    cin >> robot_no >> com >> no_of_cycle;
    command[i] = {robot_no, com, no_of_cycle};
  }

  for (int i = 0; i < c; i++) {
    // 명령 실행
    int code = DoCommand(i);
    if (code == 0) continue;

    auto [robot_no, com, no_of_cycle] = command[i];
    if (code == 1) {
      // 벽과 충돌
      cout << "Robot " << robot_no;
      cout << " crashes into the wall";
      return 0;
    } else if (code >= 2) {
      int other_robot = code - 2;
      // 다른 로봇과 충돌
      cout << "Robot " << robot_no;
      cout << " crashes into robot ";
      cout << other_robot;
      return 0;
    }
  }
  cout << "OK";
}