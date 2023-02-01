#include <bits/stdc++.h>
using namespace std;

const int MX = 200;
const int MOD = 1'000'000'000;

int a[MX + 2][MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(a[1], a[1] + MX + 1, 1);

  int n, k; cin >> n >> k;

  for(int i = 2; i <= k; i++) {
    int sum = 0;
    for(int j = 0; j <= n; j++) {
      sum += a[i - 1][j];
      if(sum > MOD) sum -= MOD;
      a[i][j] += sum;
    }
  }
  cout << a[k][n];
}