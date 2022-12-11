#include <bits/stdc++.h>
using namespace std;

int n, mx;

// 좀 더 간단히 표현 가능함. 어렵게 생각하지 말고 직관적인 로직을 구성하자.
void moveEl(int row, int col, vector<vector<int>> &b, bool (&isSummed)[22][22]) {
  int blankidx = col;
  for(int k = col - 1; k >= 0; k--) {
    if(!b[row][k]) blankidx = k; // #1. 빈 곳이라면 빈 곳 인덱스 갱신
    else {
      if(b[row][k] == b[row][col]) { // #2. 같은 숫자인 경우:
        if(!isSummed[row][k]) { // #2-1. 더한 적이 없는 경우
          b[row][k] *= 2;
          b[row][col] = 0;
          isSummed[row][k] = 1;
          return;
        }
      }
      swap(b[row][col], b[row][blankidx]); // 해당이 없는 경우 확인 중인 숫자를 빈 곳에 옮김
      return;
    }
  }
  swap(b[row][col], b[row][blankidx]);
}

// move to left (<-)
void move(vector<vector<int>> &b) {
  bool isSummed[22][22];
  for(int i = 0; i < n; i++)
    fill(isSummed[i], isSummed[i] + n, 0);
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      if(!b[i][j]) continue;
      moveEl(i, j, b, isSummed);
    }
}

vector<vector<int>> rotate(vector<vector<int>> &b) {
  vector<vector<int>> tmp;
  vector<int> row(n, 0);
  for(int i = 0; i < n; i++)
    tmp.push_back(row);
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      tmp[j][n - i - 1] = b[i][j];
  
  return tmp;
}

void solve(vector<vector<int>> b, int lv) {
  if(lv == 5) {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        mx = max(mx, b[i][j]);
    return;
  }

  vector<vector<vector<int>>> boards;
  boards.push_back(b);
  for(int rot = 0; rot < 3; rot++)
    boards.push_back(rotate(boards[rot]));

  for(auto &rb : boards) {
    move(rb);
    solve(rb, lv + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  vector<vector<int>> b;
  vector<int> row(n, 0);
  for(int i = 0; i < n; i++)
    b.push_back(row);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> b[i][j];

  solve(b, 0);
  cout << mx;
}