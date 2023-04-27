#include <bits/stdc++.h>
using namespace std;

const int MX = 20;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int sc[MX + 2][MX + 2]; // score board to select seat 
int b[MX + 2][MX + 2];
int vctcnt[MX + 2][MX + 2];

// students
struct St {
  int x, y, pr[4]; // positions and preference
  St(): x(-1), y(-1) {}
} st[MX*MX + 2];

bool oob(int x, int y) {
  return (x >= n || x < 0 || y >= n || y < 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      vctcnt[i][j] == 4;
      if(i == 0 || i == n - 1) vctcnt[i][j]--;
      if(j == 0 || j == n - 1) vctcnt[i][j]--;
    }

  int u;
  while(cin >> u) {
    memset(sc, 0, sizeof(sc));

    for(int i = 0; i < 4; i++)
      cin >> st[u].pr[i];
    
    for(int i = 0; i < 4; i++) {
      int id = st[u].pr[i];
      int fx, fy;
      tie(fx, fy) = {st[id].x, st[id].y};
      if(fx == -1 && fy == -1) continue;
      for(int dir = 0; dir < 4; dir++) {
        int nx = fx + dx[dir];
        int ny = fy + dy[dir];
        if(oob(nx, ny) || b[nx][ny]) continue;
        sc[nx][ny]++;
      }
    }

    vector<tuple<int, int, int, int>> cand;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) {
        if(b[i][j]) continue;
        cand.push_back({-sc[i][j], -vctcnt[i][j], i, j});
      }

    sort(cand.begin(), cand.end());

    auto [s, v, cx, cy] = cand[0];
    st[u].x = cx, st[u].y = cy;
    b[cx][cy] = u;
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      vctcnt[nx][ny]--;
    }
  }

  int ans = 0;
  for(int i = 1; i <= n*n; i++) {
    St s = st[i];
    int cnt = 0;
    for(int j = 0; j < 4; j++) {
      int diff = abs(st[i].x - st[s.pr[j]].x);
      diff += abs(st[i].y - st[s.pr[j]].y);
      if(diff <= 1) cnt++;
    }
    int score = 1;
    if(!cnt) { ans += 0; continue; }
    while(--cnt) { score *= 10; }
    ans += score;
  }
  cout << ans;
}