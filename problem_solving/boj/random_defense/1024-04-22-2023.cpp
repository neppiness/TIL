#include <bits/stdc++.h>
using namespace std;

int N, L;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> L;

  for(int l = L; l <= 100; l++) {
    if((N - (l - 1)*l/2)%l) continue;
    int x = (N - (l - 1)*l/2)/l;
    if(x < 0) continue;
    for(int i = 0; i < l; i++)
      cout << x + i << ' ';
    return 0;
  }
  cout << -1;
}