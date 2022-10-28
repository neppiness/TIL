#include <bits/stdc++.h>
using namespace std;

int n, m, k;
bool b[1002][1002];
int d[12][1002][1002];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solve() {
  queue<tuple<bool, int, int, int>> q;
  q.push({0, 0, 0, 0});
  d[0][0][0] = 1;
  
  bool wait;
  int cx, cy, ck;
  int nx, ny, nk;
  while(!q.empty()) {
    tie(wait, ck, cx, cy) = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      nk = ck + 1;
      nx = cx + dx[dir];
      ny = cy + dy[dir];
      if(nx >= n || nx < 0) continue;
      if(ny >= m || ny < 0) continue;
      if(b[nx][ny]) {
        if(d[ck][cx][cy] % 2 == 0) {

        } else {

        }
      } else {

      }


      if(d[ck][cx][cy] % 2 == 0) continue;
      d[ck][cx][cy]++;
      q.push({ck, cx, cy});

    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m >> k;
  
  char a;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      cin >> a;
      b[i][j] = a - '0';
    }

  cout << solve();
}
/*
넘어가기 전에 +1 존버할 수는 있는데, 그럴 거면 2를 더하고 다음으로 넘어가는 건?
-> 먼저 도달해서 BFS 자체에 문제가 생길 수 있음
*/