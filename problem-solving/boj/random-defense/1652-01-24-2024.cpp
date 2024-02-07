#include <bits/stdc++.h>
using namespace std;

char b[102][102];
int dist[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> b[i][j];
  
  int h_cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (b[i][j] == 'X') continue;
      if (j == 0) dist[i][j] = 1;
      else dist[i][j] = dist[i][j - 1] + 1;
      if (dist[i][j] == 2) h_cnt++;
    }
  }

  int v_cnt = 0;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      if (b[i][j] == 'X') continue;
      if (i == 0) dist[i][j] = 1;
      else dist[i][j] = dist[i - 1][j] + 1;
      if (dist[i][j] == 2) v_cnt++;
    }
  }

  cout << h_cnt << ' ' << v_cnt;
}
