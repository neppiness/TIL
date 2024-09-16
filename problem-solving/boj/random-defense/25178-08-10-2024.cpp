#include <bits/stdc++.h>
using namespace std;

int cnt1[26], cnt2[26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s1, s2;
  cin >> s1 >> s2;

  bool is_duramuri = 1;
  if (s1[0] != s2[0]) is_duramuri = 0;
  if (s1[n - 1] != s2[n - 1]) is_duramuri = 0;

  for (int i = 0; i < n; i++) {
    cnt1[s1[i] - 'a']++;
    cnt2[s2[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (cnt1[i] == cnt2[i]) continue;
    is_duramuri = 0;
  }
  
  string ss1 = "";
  for (char c : s1) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') continue;
    ss1 += c;
  }

  string ss2 = "";
  for (char c : s2) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') continue;
    ss2 += c;
  }

  if (ss1 != ss2) is_duramuri = 0;
  if (is_duramuri) cout << "YES";
  else cout << "NO";
}
