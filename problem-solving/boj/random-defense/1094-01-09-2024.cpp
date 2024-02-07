#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  const int MX = (1 << 7);
  
  int cnt = 0;
  for (int i = 1; i < MX; i <<= 1) {
    cnt += ((n & i) != 0);
  }
  cout << cnt;
}
