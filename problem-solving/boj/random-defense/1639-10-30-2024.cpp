#include <bits/stdc++.h>
using namespace std;

int val[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for (int i = 0; i < s.size(); i++)
    val[i] = s[i] - '0';

  int ans = 0;
  for (int l = 2; l <= s.size(); l += 2) {
    // i는 시작 인덱스
    for (int i = 0; i <= s.size() - l; i++) {
      int left_sum = 0;
      for (int j = i; j < i + l/2; j++)
        left_sum += val[j];
      int right_sum = 0;
      for (int j = i + l/2; j < i + l; j++)
        right_sum += val[j];
      if (left_sum == right_sum) ans = max(ans, l);
    }
  }
  cout << ans;
}
