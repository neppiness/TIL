#include <bits/stdc++.h>
using namespace std;

int n, no;
vector<int> ans;

bool b[27][27];
bool vis[27][27];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve(int x, int y) {
  queue<pair<int,int>> q;
  int cx, cy, nx, ny;
  int cnt = 0;
  q.push({x, y});
  while(!q.empty()) {
    tie(cx, cy) = q.front(); q.pop();
    vis[cx][cy] = 1;
    cnt++;
    for(int d = 0; d < 4; d++) {
      nx = cx + dx[d];
      ny = cy + dy[d];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;
      if(!b[nx][ny] || vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
  ans.push_back(cnt);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  char x;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> x;
      b[i][j] = x - '0';
    }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      if(!b[i][j] || vis[i][j]) continue;
      no++;
      solve(i, j);
    }
  cout << no << '\n';

  sort(ans.begin(), ans.end());
  for(int c : ans) cout << c << '\n';
}