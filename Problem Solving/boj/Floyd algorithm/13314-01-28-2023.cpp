#include <bits/stdc++.h>
using namespace std;

int dist[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 100;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      dist[i][j] = 10000;
      if(i == n - 1 || j == n - 1) dist[i][j] = 4999;
      if(i == j) dist[i][j] = 0;
    }

  cout << n << '\n';
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cout << dist[i][j] << " \n"[j + 1 == n];
}