#include <bits/stdc++.h>
using namespace std;

int q[1002][2]; // q[idx][PM]
int a_cnt, n_cnt, p_cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(q, -1, sizeof(q));

  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a; char b; bool c;
    cin >> a >> b >> c;
    q[a][b == 'M'] = c;
  }
  for (int i = 1; i <= n; i++) {
    if (q[i][0] == 1 && q[i][1] == 0) {
      p_cnt++;
    } else if (q[i][0] == 1 && q[i][1] == -1) {
      a_cnt++;
    } else if (q[i][0] == -1 && q[i][1] == 0) {
      a_cnt++;
    } else if (q[i][0] == -1 && q[i][1] == -1) {
      a_cnt++;
    } else {
      n_cnt++;
    }
  }
  cout << p_cnt << ' ' << p_cnt + a_cnt;
}
