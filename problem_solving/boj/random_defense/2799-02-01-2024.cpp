#include <bits/stdc++.h>
using namespace std;

char b[503][503];
int ans[5];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < 5*n + 1; i++)
    cin >> b[i];

  for (int i = 1; i < 5*n + 1; i += 5) {
    for (int j = 1; j < 5*m + 1; j += 5) {
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        cnt += (b[i + k][j] == '*');
      }
      ans[cnt]++;
    }
  }
  for (int i = 0; i < 5; i++)
    cout << ans[i] << ' ';
}
