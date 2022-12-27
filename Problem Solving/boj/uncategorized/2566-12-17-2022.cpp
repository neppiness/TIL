#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int mx = -1, mi, mj;

  for(int i = 1; i <= 9; i++)
    for(int j = 1; j <= 9; j++) {
      int n; cin >> n;
      if(mx < n) tie(mx, mi, mj) = {n, i, j};
    }
  cout << mx << '\n' << mi << ' ' << mj;
}