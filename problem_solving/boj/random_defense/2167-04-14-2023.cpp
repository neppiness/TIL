#include <bits/stdc++.h>
using namespace std;

const int MX = 302;

int n, m;
int b[MX][MX], s[MX][MX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) {
      cin >> b[i][j];
    }

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      s[i][j] += s[i][j - 1] + b[i][j];

  for(int j = 1; j <= m; j++)
    for(int i = 1; i <= n; i++)
      s[i][j] += s[i - 1][j];

  int k; cin >> k;
  while(k--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << s[c][d] + s[a - 1][b - 1] - s[c][b - 1] - s[a - 1][d] << '\n';
  }
}