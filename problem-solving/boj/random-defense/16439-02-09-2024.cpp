#include <bits/stdc++.h>
using namespace std;

int n, m;
int score[32][32];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> score[i][j];

  bool select[m] = {};
  for (int i = m - 3; i < m; i++)
    select[i] = 1;

  int ans = 0;
  do {
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      int sc = 0;
      for (int j = 0; j < m; j++) {
        if (!select[j]) continue;
        sc = max(sc, score[i][j]);
      }
      tmp += sc;
    }
    ans = max(ans, tmp);
  } while (next_permutation(select, select + m));
  cout << ans;
}
