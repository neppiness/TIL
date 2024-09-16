#include <bits/stdc++.h>
using namespace std;

int n; 
int a[102][102];
int temp[102][102];

void rot() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      temp[j][n - i + 1] = a[i][j];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = temp[i][j];
}

void move() {
  int x; cin >> x;
  int la = a[x][n];
  for (int j = n - 1; j >= 1; j--)
    a[x][j + 1] = a[x][j];
  a[x][1] = la;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];

  int q; cin >> q;
  while (q--) {
    int x; cin >> x;
    if (x == 1) move();
    else rot();
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}
