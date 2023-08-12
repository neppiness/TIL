#include <bits/stdc++.h>
using namespace std;

char board[1002][1002];
int width[1002][1002];
int MXW;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    cin >> board[i];
    for(int j = 0; j < m; j++)
      board[i][j] -= '0';
  }

  for(int i = 1; i < n; i++)
    for(int j = 1; j < m; j++) {
      width[i][j] = board[i][j] + min(min(board[i][j-1], board[i-1][j-1]), board[i-1][j]);
      MXW = max(MXW, width[i][j]);
    }
  cout << MXW*MXW;
}