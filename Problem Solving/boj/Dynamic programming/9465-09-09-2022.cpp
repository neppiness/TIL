#include <bits/stdc++.h>
using namespace std;

int t, n;
int board[2][100'002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < n; j++)
        cin >> board[i][j];
    
    if(n == 1) {
      cout << max(board[0][0], board[1][0]) << '\n';
      continue;
    }
    board[0][1] += board[1][0];
    board[1][1] += board[0][0];
    
    for(int j = 2; j < n; j++)
      for(int i = 0; i < 2; i++)
        board[i][j] += max(board[(i+1)%2][j-1], board[(i+1)%2][j-2]);
    cout << max(board[0][n-1], board[1][n-1]) << '\n';
  }
}