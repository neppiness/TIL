#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int is_mirror[52][52]; // 0: 거울 없음, 1: \ 방향, 2: / 방향 거울
bool is_visited[52][52];
char b[52][52];
pair<int, int> st, en;

int cnt = 0, ans = 2500;

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= n || y < 0;
}

int dir_for_mirror1(int dir) {
  if (dir == 0) return 1;
  if (dir == 1) return 0;
  if (dir == 2) return 3;
  return 2;
}

int dir_for_mirror2(int dir) {
  if (dir == 0) return 3;
  if (dir == 1) return 2;
  if (dir == 2) return 1;
  return 0;
}

void solve(pair<int, int> cur, int dir) {
  auto [cx, cy] = cur;
  if (cur == en) {
    ans = min(ans, cnt);
    return;
  }
  if (oob(cx, cy)) return;


  if (b[cx][cy] == '!') {
    if (is_mirror[cx][cy] == 0) {
      cnt++;
      is_mirror[cx][cy] = 1;
      int ndir = dir_for_mirror1(dir);
      int nx = cx + dx[ndir];
      int ny = cy + dy[ndir];
      if (!is_visited[nx][ny]) {
        is_visited[nx][ny] = 1;
        solve({nx, ny}, ndir);
        is_visited[nx][ny] = 0;
      }
      
      is_mirror[cx][cy] = 2;
      ndir = dir_for_mirror2(dir);
      nx = cx + dx[ndir];
      ny = cy + dy[ndir];
      if (!is_visited[nx][ny]) {
        is_visited[nx][ny] = 1;
        solve({nx, ny}, ndir);
        is_visited[nx][ny] = 0;
      }
      is_mirror[cx][cy] = 0;
      cnt--;
    } else {
      int ndir;
      if (is_mirror[cx][cy] == 1) {
        ndir = dir_for_mirror1(dir);
      } else {
        ndir = dir_for_mirror2(dir);
      }
      int nx = cx + dx[ndir];
      int ny = cy + dy[ndir];
      if (!is_visited[nx][ny]) {
        is_visited[nx][ny] = 1;
        solve({nx, ny}, ndir);
        is_visited[nx][ny] = 0;
      }
    }
  }
  int nx = cx + dx[dir];
  int ny = cy + dy[dir];
  if (is_visited[nx][ny]) return;
  is_visited[nx][ny] = 1;
  solve({nx, ny}, dir);
  is_visited[nx][ny] = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  st = {-1, -1};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c = b[i][j];
      if (c != '#') continue;
      if (st.first == -1) {
        st = {i, j};
      } else {
        en = {i, j};
      }
    }
  }

  for (int dir = 0; dir < 4; dir++)
    solve(st, dir);
  cout << ans;
}
