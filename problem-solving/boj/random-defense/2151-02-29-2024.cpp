#include <bits/stdc++.h>
using namespace std;

int n; 
char b[52][52];
pair<int, int> st, en;
priority_queue< tuple<int, int, int, int, vector<int>>,
    vector<tuple<int, int, int, int, vector<int>>>,
    greater<tuple<int, int, int, int, vector<int>>> > pq;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= n || y < 0;
}

int dir_mirror1(int dir) { // / 거울
  if (dir == 0) return 3;
  if (dir == 1) return 2;
  if (dir == 2) return 1;
  return 0;
}

int dir_mirror2(int dir) { // \ 거울
  if (dir == 0) return 1;
  if (dir == 1) return 0;
  if (dir == 2) return 3;
  return 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  st = {-1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
      if (b[i][j] != '#') continue;
      if (st.first == -1) {
        st = {i, j};
      } else {
        en = {i, j};
      }
    }
  }

  pq.push({0, st.first, st.second, 0, vector<int>(2500)});
  pq.push({0, st.first, st.second, 1, vector<int>(2500)});
  pq.push({0, st.first, st.second, 2, vector<int>(2500)});
  pq.push({0, st.first, st.second, 3, vector<int>(2500)});
  while (!pq.empty()) {
    auto [dist, cx, cy, dir, v] = pq.top();
    pq.pop();

    if (cx == en.first && cy == en.second) {
      cout << dist;
      return 0;
    }
    
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if (!oob(nx, ny) && b[nx][ny] != '*') {
      pq.push(dist, nx, ny, dir, v);
    }
    if (b[cx][cy] != '!') continue;
    
    int no = cx * n + cy;
    v[no]++;
    int ndir = dir_mirror1(dir);
    nx = cx + dx[ndir];
    ny = cy + dy[ndir];
    if (!oob(nx, ny) && b[nx][ny] != '*') {
      pq.push(dist, nx, ny, ndir, v);
    }

    v[no]++;
    ndir = dir_mirror2(dir);
    nx = cx + dx[ndir];
    ny = cy + dy[ndir];
    if (!oob(nx, ny) && b[nx][ny] != '*') {
      pq.push(dist, nx, ny, ndir, v);
    }
  }
}
