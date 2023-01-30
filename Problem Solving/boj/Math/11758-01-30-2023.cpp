#include <bits/stdc++.h>
using namespace std;

int x[3], y[3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 3; i++)
    cin >> x[i] >> y[i];
  
  int ab[2] = {x[1] - x[0], y[1] - y[0]};
  int bc[2] = {x[2] - x[1], y[2] - y[1]};
  int pd = ab[0] * bc[1] - ab[1] * bc[0];

  if(pd > 0) cout << 1;
  else if(pd < 0) cout << -1;
  else cout << 0;
}