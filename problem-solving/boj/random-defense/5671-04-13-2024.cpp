#include <bits/stdc++.h>
using namespace std;

int cnt[5002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 5000; i++) {
    string no = to_string(i);
    bool chk[10] = {}, is_valid = 1;
    for (char c : no) {
      int idx = c - '0';
      if (chk[idx]) {
        is_valid = 0;
        break;
      }
      chk[idx] = 1;
    }
    cnt[i] = cnt[i - 1] + is_valid;
  }

  int n, m;
  while (cin >> n >> m) {
    cout << cnt[m] - cnt[n - 1] << '\n'; 
  }
}
