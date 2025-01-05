#include <bits/stdc++.h>
using namespace std;

string rsp[12];
bool live[12];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> rsp[i];
      live[i] = 1;
    }

    int m = rsp[0].size();
    for (int j = 0; j < m; j++) {
      int cnt[3] = {};
      for (int i = 0; i < n; i++) {
        if (!live[i]) continue;
        char c = rsp[i][j];
        switch (c) {
          case 'R':
            cnt[0]++;
            break;
          case 'S':
            cnt[1]++;
            break;
          default:
            cnt[2]++;
        }
      }
      if (cnt[0] && cnt[1] && cnt[2]) continue;
      if (!cnt[0] && !cnt[1]) continue;
      if (!cnt[1] && !cnt[2]) continue;
      if (!cnt[0] && !cnt[2]) continue;
      if (!cnt[0]) {
        for (int i = 0; i < n; i++)
          if (rsp[i][j] == 'P') live[i] = 0;
      } else if (!cnt[1]) {
        for (int i = 0; i < n; i++)
          if (rsp[i][j] == 'R') live[i] = 0;
      } else {
        for (int i = 0; i < n; i++)
          if (rsp[i][j] == 'S') live[i] = 0;
      }
    }

    int lcnt = 0;
    for (int i = 0; i < n; i++)
      lcnt += live[i];

    if (lcnt == 1) {
      for (int i = 0; i < n; i++) {
        if (live[i]) cout << i + 1 << '\n';
      }
    } else {
      cout << 0 << '\n';
    }
  }
}
