#include <bits/stdc++.h>
using namespace std;

int h, w;
char b[3074][6144];

void tri(int x, int y, int hgt) {
  if(hgt == 3) {
    for(int j = 0; j < 5; j++) b[x][y + j] = '*';
    for(int j = 1; j < 5; j = j + 2) b[x + 1][y + j] = '*';
    b[x + 2][y + 2] = '*';
    return;
  }
  tri(x, y, hgt/2);
  tri(x, y + hgt, hgt/2);
  tri(x + hgt/2, y + hgt/2, hgt/2);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> h;
  w = 2*(h - 1) + 1;

  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
      b[i][j] = ' ';

  tri(0, 0, h);
  for(int i = h - 1; i >= 0; i--) {
    for(int j = 0; j < w; j++)
      cout << b[i][j];
    cout << '\n';
  }
}