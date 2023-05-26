#include <bits/stdc++.h>
using namespace std;

bool is_used[102];
bool is_occupied[12][12];

int n;
int b[12][12];
int ans = 0x7f7f7f7f;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct Flower {
  int x, y;
  Flower(int x_, int y_): x(x_), y(y_) {}

  bool IsInvalid() {
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n) return 1;
      if (ny < 0 || ny >= n) return 1;
      if (is_occupied[nx][ny]) return 1;
    }
    return 0;
  }

  void SetFlower(bool set) {
    is_occupied[x][y] = set;
    for (int dir = 0; dir < 4; dir++)
      is_occupied[x + dx[dir]][y + dy[dir]] = set;
  }

  int GetPrice() {
    int sum = b[x][y];
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      sum += b[nx][ny];
    }
    return sum;
  }
};

void solve(int lv, int st, int tot) {
  if (lv == 0) { ans = min(ans, tot); return; }
  for (int i = st; i < n*n; i++) {
    Flower f = Flower(i / n, i % n);
    if (f.IsInvalid()) continue;
    f.SetFlower(1);
    solve(lv - 1, i + 1, tot + f.GetPrice());
    f.SetFlower(0);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> b[i][j];
  
  solve(3, 0, 0);
  cout << ans;
}