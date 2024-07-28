#include <bits/stdc++.h>
using namespace std;

int board[102][102];
bool exists[10002];
string output[] = {"FALSE", "TRUE"};

bool solve() {
  int n; cin >> n;
  bool duplicated = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x; cin >> x;
      board[i][j] = x;
      if (!exists[x]) {
        exists[x] = 1;
        continue;
      }
      duplicated = 1;
    }
  }
  if (duplicated) return 0;
  
  int sum = n * (n * n + 1) / 2;
  for (int i = 0; i < n; i++) {
    int calc = 0;
    for (int j = 0; j < n; j++)
      calc += board[i][j];
    if (calc != sum) return 0;
  }

  for (int j = 0; j < n; j++) {
    int calc = 0;
    for (int i = 0; i < n; i++) {
      calc += board[i][j];
    }
    if (calc != sum) return 0;
  }

  int dia_calc = 0;
  for (int i = 0; i < n; i++)
    dia_calc += board[i][i];
  if (dia_calc != sum) return 0;

  dia_calc = 0;
  for (int i = 0; i < n; i++)
    dia_calc += board[i][n - 1 - i];
  if (dia_calc != sum) return 0;

  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << output[solve()];
}
