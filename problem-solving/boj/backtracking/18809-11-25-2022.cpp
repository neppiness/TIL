#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;

vector<pair<int, int>> pts; // 배양액을 뿌릴 수 있는 지점의 좌표를 기록
vector<int> comb;

int n, m, r, g;
int dist[52][52];
bool flower[52][52];

int mx;
int board[52][52];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

bool chkrg(int x, int y) { return ((x == 3 && y == 4) || (x == 4 && y == 3)); }

void solve() {
  int cnt = 0;
  int b[52][52];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      b[i][j] = board[i][j];

  for(int i = 0; i < n; i++) {
    fill(dist[i], dist[i] + m, -1);
    fill(flower[i], flower[i] + m, 0);
  }

  int x, y;
  for(int a = 0; a < pts.size(); a++) {
    if(comb[a] == 0) continue;
    tie(x, y) = pts[a];
    b[x][y] = comb[a];
    dist[x][y] = 0;
    q.push({x, y});
  }

  int cx, cy;
  while(!q.empty()) {
    tie(cx, cy) = q.front(); q.pop();
    if(flower[cx][cy]) continue; // 큐에 들어갔지만 꽃을 틔워서 이 배양액에 의한 흐름을 막아야 하는 경우
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;

      int& cb = b[cx][cy];
      int& nb = b[nx][ny];
      if(nb == 0) continue;
      if(dist[nx][ny] != -1) { // 만약 전파하려는 곳이 이미 배양액이 흐른 곳이라면
        if(dist[nx][ny] == dist[cx][cy] + 1) // 그리고 그 거리 차이가 1인 경우
          if(!flower[nx][ny] && chkrg(cb, nb)) {
            cnt++;
            flower[nx][ny] = 1;
          }
        continue;
      }
      nb = cb;
      dist[nx][ny] = dist[cx][cy] + 1;
      q.push({nx, ny});
    }
  }
  mx = max(mx, cnt);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> r >> g;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
      if(board[i][j] == 2)
        pts.push_back({i, j});
    }
  
  int ptsz = pts.size();

  for(int i = 0; i < ptsz - r - g; i++)
    comb.push_back(0); // 배양액을 뿌리지 않을 칸은 comb 벡터의 0으로 표현
  for(int i = 0; i < r; i++)
    comb.push_back(3); // 빨간색 배양액은 comb 벡터의 3로 표현
  for(int i = 0; i < g; i++)
    comb.push_back(4); // 초록색 배양액은 comb 벡터의 4로 표현

  do solve();
  while(next_permutation(comb.begin(), comb.end()));

  cout << mx;
}