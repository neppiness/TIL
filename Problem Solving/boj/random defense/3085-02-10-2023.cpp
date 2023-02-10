#include <bits/stdc++.h>
using namespace std;

const int MX = 50 + 2;

int n, ans = 1;
int dx[] = {1, 0};
int dy[] = {0, 1};

char b[MX][MX];

bool oob(int x, int y) { return (x >= n || y >= n); }

void solve(int cx, int cy) {
  for(int dir = 0; dir < 2; dir++) {
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(oob(nx, ny)) continue;
    swap(b[cx][cy], b[nx][ny]);

    for(int i = cx; i <= nx; i++) {
      int cnt = 1;
      for(int j = 1; j < n; j++) {
        if(b[i][j] == b[i][j - 1]) {
          cnt++;
          ans = max(cnt, ans);
        }
        else cnt = 1;
      }
    }
    for(int j = cy; j <= ny; j++) {
      int cnt = 1;
      for(int i = 1; i < n; i++) {
        if(b[i - 1][j] == b[i][j]) {
          cnt++;
          ans = max(cnt, ans);
        }
        else cnt = 1;
      }
    }
    swap(b[cx][cy], b[nx][ny]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> b[i];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      solve(i, j);

  cout << ans;
}