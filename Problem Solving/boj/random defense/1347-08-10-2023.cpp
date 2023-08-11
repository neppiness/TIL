#include <bits/stdc++.h>
using namespace std;

const int ST = 51;

char b[103][103];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int r1 = ST, r2 = ST;
int c1 = ST, c2 = ST;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for (int i = 0; i <= 102; i++)
    for (int j = 0; j <= 102; j++)
      b[i][j] = '#';
  
  b[ST][ST] = '.';

  int n; cin >> n; 
  string s; cin >> s;

  int dir = 0; // 'R': dir 감소, 'L': dir 증가
  int cx = ST, cy = ST;
  for (char c : s) {
    if (c == 'R') {
      dir = (dir + 3) % 4;
    } else if (c == 'L') {
      dir = (dir + 1) % 4;
    } else { // c == 'F'
      cx = cx + dx[dir];
      cy = cy + dy[dir];
      b[cx][cy] = '.';
      r1 = min(r1, cx);
      r2 = max(r2, cx);
      c1 = min(c1, cy);
      c2 = max(c2, cy);
    }
  }

  for (int i = r1; i <= r2; i++) {
    for (int j = c1; j <= c2; j++)
      cout << b[i][j];
    cout << '\n';
  }
}
