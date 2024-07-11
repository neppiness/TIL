#include <bits/stdc++.h>
using namespace std;

int board[1002][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  pair<int, int> st, en;
  st = {-1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x; cin >> x;
      board[i][j] = x;
      if (x == 2 || x == 5) {
        if (st.first != -1) {
          en = {i, j};
        } else {
          st = {i, j};
        }
      }
    }
  }
  int dx = (st.first - en.first);
  int dy = (st.second - en.second);
  int dist = dx * dx + dy * dy;
  pair<int, int> stt, enn;
  stt = {min(st.first, en.first), max(st.first, en.first)};
  enn = {min(st.second, en.second), max(st.second, en.second)};
  int cnt = 0;
  for (int i = stt.first; i <= stt.second; i++)
    for (int j = enn.first; j <= enn.second; j++)
      cnt += (board[i][j] == 1);
  cout << (cnt >= 3 && dist >= 25);
}
