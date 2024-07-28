#include <bits/stdc++.h>
using namespace std;

string s[102];

string solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      string ss1 = s[i] + s[j];
      string ss2 = s[j] + s[i];
      bool is_pal = 1;
      for (int k = 0; k < ss1.length(); k++) {
        if (ss1[k] != ss1[ss1.length() - 1 - k]) is_pal = 0;
      }
      if (is_pal) return ss1;
      is_pal = 1;
      for (int k = 0; k < ss2.length(); k++) {
        if (ss2[k] != ss2[ss2.length() - 1 - k]) is_pal = 0;
      }
      if (is_pal) return ss2;
    }
  }
  return "0";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--)
    cout << solve() << '\n';
}
