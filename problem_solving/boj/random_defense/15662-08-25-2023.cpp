#include <bits/stdc++.h>
using namespace std;

int n;
int rot[1002]; // 0: nothing, 1: cw, 2: ccw
bool g[1002][8]; // g[id][ns], 0: n, 1: s

void setLeftRotation(int no, int prvdir) {
  if (no < 0) return;
  if (g[no][2] == g[no + 1][6]) return;
  rot[no] = - prvdir; 
  setLeftRotation(no - 1, - prvdir);
}

void setRightRotation(int no, int prvdir) {
  if (no >= n) return;
  if (g[no][6] == g[no - 1][2]) return;
  rot[no] = - prvdir; 
  setRightRotation(no + 1, - prvdir);
}

void rotateAll() {
  for (int i = 0; i < n; i++) {
    if (rot[i] == 1) rotate(g[i], g[i] + 7, g[i] + 8);
    if (rot[i] == -1) rotate(g[i], g[i] + 1, g[i] + 8);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (int j = 0; j < 8; j++) 
      g[i][j] = (s[j] == '1');
  }

  int t; cin >> t;
  while (t--) {
    int no, dir;
    cin >> no >> dir;
    no--;

    memset(rot, 0, sizeof(rot));
    rot[no] = dir;

    setLeftRotation(no - 1, dir);
    setRightRotation(no + 1, dir);
    rotateAll();
  }

  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += g[i][0];
  cout << cnt;
}
