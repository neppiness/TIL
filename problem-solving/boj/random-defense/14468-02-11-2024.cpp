#include <bits/stdc++.h>
using namespace std;

int idx[26][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(idx, -1, sizeof(idx));
  
  string s; cin >> s;
  for (int i = 0; i < 52; i++) {
    int x = s[i] - 'A';
    if (idx[x][0] == -1) {
      idx[x][0] = i;
    } else {
      idx[x][1] = i;
    }
  }

  int ans = 0;
  for (int i = 0; i < 26; i++) {
    int st = idx[i][0];
    int en = idx[i][1];
    for (int j = i + 1; j < 26; j++) {
      int cnt = 0;
      for (int k = 0; k < 2; k++) {
        cnt += (st < idx[j][k] && idx[j][k] < en);
      }
      ans += (cnt == 1);
    }
  }
  cout << ans;
}
