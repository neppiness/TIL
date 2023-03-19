#include <bits/stdc++.h>
using namespace std;

const int MX = 1515;
const int MOD = 1'000'000'007;

int N;
int bi[MX + 2][MX + 2]; // bi[n][r] = nCr

int bino(int n, int r) {
  int &ret = bi[n][r];
  if(r == 0 || n == r) ret = 1;
  if(ret != -1) return ret;
  ret = bino(n - 1, r - 1) + bino(n - 1, r);
  if(ret > MOD) ret -= MOD;
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(bi, -1, sizeof(bi));

  cin >> N;
  int ans = 0;
  for(int i = 0; i <= N - 1; i++) {
    int rest = i * 5 + (N - 1 - i) * 10 + 5;
    if(rest % 15 == 0) ans += bino(N - 1, i);
    if(ans > MOD) ans -= MOD;
  }
  cout << ans;
}