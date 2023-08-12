#include <bits/stdc++.h>
using namespace std;

const int N = 10;
const int INF = 0x7f7f7f7f;

int ans = INF;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool b[10][10];  // 0: 전구가 꺼진 경우, 1: 전구가 켜진 경우
bool b2[10][10]; // 풀이용 보드

bool oob(int x, int y) {
  return (x < 0 || x >= N || y < 0 || y >= N);
}

// 켜거나 끈다는 동작의 정의, 복사된 배열인 b2에 대해서 동작
void toggle(int cx, int cy) {
  b2[cx][cy] = !b2[cx][cy];
  for(int dir = 0; dir < 4; dir++) {
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(oob(nx, ny)) continue;
    b2[nx][ny] = !b2[nx][ny];
  }
}

void copyBoard() {
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      b2[i][j] = b[i][j];
}

bool checkIfCompleted() {
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      if(b2[i][j]) return 0;
  return 1;
}

int solve() {
  bool comb[N] = {};
  for(int c = 0; c <= N; c++) {
    if(c != 0) comb[c - 1] = 1;
    do {
      int cnt = c;
      copyBoard();
      for(int j = 0; j < N; j++)
        if(comb[j]) toggle(0, j);
      
      for(int i = 1; i < N; i++)
        for(int j = 0; j < N; j++)
          if(b2[i - 1][j]) { toggle(i, j); cnt++; }
      bool is_completed = checkIfCompleted();
      if(is_completed) ans = min(ans, cnt);
    } while(prev_permutation(comb, comb + N));
  }
  if(ans == INF) return -1;
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++) {
      char c; cin >> c;
      b[i][j] = (c == 'O');
    }
  cout << solve();
}