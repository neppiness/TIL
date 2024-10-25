#include <bits/stdc++.h>
using namespace std;

int sc[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int memo[202][202];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  int common = min(n, m);
  
  for (int i = 0; i < common; i++) {
    memo[0][2*i] += sc[s[i] - 'A'];
    memo[0][2*i + 1] += sc[t[i] - 'A'];
  }

  if (n > common) {
    for (int i = common; i < n; i++)
      memo[0][common + i] += sc[s[i] - 'A'];
  }
  if (m > common) {
    for (int i = common; i < m; i++)
      memo[0][common + i] += sc[t[i] - 'A'];
  }

  for (int i = 1; i < n + m - 1; i++)
    for (int j = 0; j < n + m - i; j++)
      memo[i][j] = (memo[i - 1][j] + memo[i - 1][j + 1]) % 10;

  cout << memo[n + m - 2][0] * 10 + memo[n + m - 2][1] << '%';
}
