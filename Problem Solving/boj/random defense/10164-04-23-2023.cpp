#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll c[30][30];
int N, M, K;

ll comb(int n, int r) {
  ll &ret = c[n][r];
  if(ret != -1) return ret;
  if(r == 0 || n == r) return 1;
  return ret = comb(n - 1, r) + comb(n - 1, r - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(c, -1, sizeof(c));

  cin >> N >> M >> K;
  if(K == 0) K = 1;
  int X = (K - 1) / M;
  int Y = (K - 1) % M;

  cout << comb(N + M - 2 - X - Y, M - Y - 1) * comb(X + Y, Y) << '\n';
}