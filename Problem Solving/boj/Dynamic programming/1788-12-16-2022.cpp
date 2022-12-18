#include <bits/stdc++.h>
using namespace std;

const int M = 1'000'000;
const int B = 1'000'000'000;
int p[2'000'004];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  int idx = n + M;

  p[M - 1] = 1;
  p[M + 1] = 1;

  for(int i = M + 2; i <= 2 * M + 1; i++)
    p[i] = (p[i - 1] + p[i - 2]) % B;
  for(int i = M + 1; i >= 2; i--)
    p[i - 2] = (p[i] - p[i - 1]) % B;

  if(p[idx] == 0) cout << 0 << '\n';
  else if(p[idx] < 0) cout << -1 << '\n';
  else cout << 1 << '\n';
  cout << abs(p[idx]);
}