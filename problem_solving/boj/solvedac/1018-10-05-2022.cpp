#include <bits/stdc++.h>
using namespace std;

bool s[52][52][2];
int ans = 987987987;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  char a;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      cin >> a;
      if((i + j)%2 == 0) {
        s[i][j][0] = (a == 'B');
        s[i][j][1] = (a == 'W');
      } else {
        s[i][j][0] = (a == 'W');
        s[i][j][1] = (a == 'B');
      }
    }

  for(int k = 0; k < 2; k++) {
    for(int i = 0; i <= n - 8; i++)
      for(int j = 0; j <= m - 8; j++) {
        int cnt = 0;
        for(int q = 0; q < 8; q++)
          for(int p = 0; p < 8; p++)
            cnt += s[i + q][j + p][k];
        ans = min(cnt, ans);
      }
  }
  cout << ans;
}