#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'002;
bool p[MX];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fill(p, p + MX, 1);
  p[1] = 0;
  for(int i = 2; i < MX; i++) {
    if(!p[i]) continue;
    for(int j = 2; j < MX / i; j++)
      p[i * j] = 0;
  }

  int m, n;
  cin >> m >> n;

  for(int i = 0; i < MX; i++)
    if(i >= m && i <= n && p[i])
      cout << i << '\n';
}