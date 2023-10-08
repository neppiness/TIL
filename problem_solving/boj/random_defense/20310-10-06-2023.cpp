#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int one_cnt = 0, zero_cnt = 0;
  for (char c : s) {
    one_cnt += (c == '1');
    zero_cnt += (c == '0');
  }

  one_cnt /= 2;
  zero_cnt /= 2;

  int one_idx = 0, zero_idx = s.size() - 1;
  for (; one_idx < s.size(); one_idx++) {
    if (one_cnt == 0) break;
    if (s[one_idx] == '1') one_cnt--;
  }

  for (; zero_idx >= 0; zero_idx--) {
    if (zero_cnt == 0) break;
    if (s[zero_idx] == '0') zero_cnt--;
  }

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0' & i > zero_idx) continue;
    if (s[i] == '1' & i < one_idx) continue;
    cout << s[i];
  }
}
