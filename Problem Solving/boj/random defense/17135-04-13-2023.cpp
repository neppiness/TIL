#include <bits/stdc++.h>
using namespace std;

const int MX = 17;

int n, m, d_lim, ans, cnt;
// 원래 보드판과 궁수 위치를 조정한 후에 게임을 진행하는 임시 보드판
// n번째 열에는 궁수를 배치한다.
int A[MX][MX], a[MX][MX]; // 0은 빈 칸. 1은 적이 있는 칸. 2는 죽을 적. 3은 궁수.

bool oob(int x, int y) { return (x < 0 || y < 0 || x >= n || y >= m); }

bool is_enemy_remain() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(a[i][j]) return 1;
  return 0;
}

void check(int j) {
  for(int d = 1; d <= d_lim; d++) {
    int x = n, y = j - d;
    while(y != j) {
      if(!oob(x, y) && a[x][y]) { a[x][y] = 2; return; }
      x--; y++;
    }
    while(x != n) {
      if(!oob(x, y) && a[x][y]) { a[x][y] = 2; return; }
      x++; y++;
    }
  }
}

void check() {
  for(int j = 0; j < m; j++)
    if(a[n][j] == 3) check(j);
}

void remove() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      if(a[i][j] != 2) continue;
      a[i][j] = 0;
      cnt++;
    }
}

void progress() {
  for(int i = n - 1; i >= 0; i--)
    for(int j = 0; j < m; j++) {
      if(!a[i][j]) continue;
      if(a[i][j] == 1 && !oob(i + 1, j)) a[i + 1][j] = 1;
      a[i][j] = 0;
    }
}

void solve() {
  cnt = 0;
  for(int i = 0; i <= n; i++)
    for(int j = 0; j < m; j++)
      a[i][j] = A[i][j];

  while(is_enemy_remain()) {
    check();
    remove();
    progress();
  }
  ans = max(ans, cnt);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> d_lim;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> A[i][j];
  
  for(int j = 0; j < 3; j++)
    A[n][j] = 3; //  궁수 배치.

  do { solve(); } while(
      prev_permutation(A[n], A[n] + m)
  );
  cout << ans;
}