#include <bits/stdc++.h>
using namespace std;

const string JOLLY[] = {"Not jolly", "Jolly"};

bool cnt[3002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    memset(cnt, 0, sizeof(cnt));
    int cur; cin >> cur;
    int nxt;
    bool is_jolly = 1;
    for (int i = 1; i < n; i++) {
      cin >> nxt;
      int d = abs(cur - nxt);
      cur = nxt;
      if (d <= 0 || d >= n) {
        is_jolly = 0;
        continue;
      }
      cnt[d] = 1;
    }

    for (int i = 1; i < n; i++) {
      if (cnt[i]) continue;
      is_jolly = 0;
    }
    cout << JOLLY[is_jolly] << '\n';
  }
}
