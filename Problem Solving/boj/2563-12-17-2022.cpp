#include <bits/stdc++.h>
using namespace std;

bool b[115][115];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--) {
    int x, y; cin >> x >> y;
    for(int i = x; i < x + 10; i++)
      for(int j = y; j < y + 10; j++)
        b[i][j] = 1;
  }

  int cnt = 0;
  for(int i = 0; i < 100; i++)
    for(int j = 0; j < 100; j++)
      cnt += b[i][j];

  cout << cnt;
}