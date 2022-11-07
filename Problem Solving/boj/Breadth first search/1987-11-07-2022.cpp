#include <bits/stdc++.h>
using namespace std;

char b[22][22];
bool alpha[26];
int dist[22][22];

int mx;
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int ctoi(char a) { return (int)(a - 'A'); }

void dfs(int cx, int cy) {
  int nx, ny;
  for(int dir = 0; dir < 4; dir++) {
    nx = cx + dx[dir];
    ny = cy + dy[dir];
    
    if(nx >= n || nx < 0) continue;
    if(ny >= m || ny < 0) continue;
    if(dist[nx][ny] || alpha[ctoi(b[nx][ny])]) continue;

    alpha[ctoi(b[nx][ny])] = 1;
    dist[nx][ny] = dist[cx][cy] + 1;
    mx = max(mx, dist[nx][ny]);

    dfs(nx, ny);
    
    alpha[ctoi(b[nx][ny])] = 0;
    dist[nx][ny] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> b[i][j];

  alpha[ctoi(b[0][0])] = 1;
  dist[0][0] = 1;
  mx = 1;
  dfs(0, 0);
  cout << mx;
}