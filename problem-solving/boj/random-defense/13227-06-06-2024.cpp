#include <bits/stdc++.h>
using namespace std;

char board[3][3];

bool has_winner(int x1, int y1, int x2, int y2, int x3, int y3) {
  if (board[x1][y1] == '.') return 0;
  if (board[x1][y1] != board[x2][y2]) {
    return 0;
  } else if (board[x1][y1] != board[x3][y3]) {
    return 0;
  } else if (board[x2][y2] != board[x3][y3]) {
    return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 3; i++)
    cin >> board[i];

  if (has_winner(0, 0, 1, 1, 2, 2)) {
    cout << "YES";
  } else if (has_winner(2, 0, 1, 1, 0, 2)) {
    cout << "YES";
  } else if (has_winner(0, 0, 0, 1, 0, 2)) {
    cout << "YES";
  } else if (has_winner(1, 0, 1, 1, 1, 2)) {
    cout << "YES";
  } else if (has_winner(2, 0, 2, 1, 2, 2)) {
    cout << "YES";
  } else if (has_winner(0, 0, 1, 0, 2, 0)) {
    cout << "YES";
  } else if (has_winner(0, 1, 1, 1, 2, 1)) {
    cout << "YES";
  } else if (has_winner(0, 2, 1, 2, 2, 2)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
