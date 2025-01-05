#include <bits/stdc++.h>
using namespace std;

int cnt[26];
int cnt1[26];
int cnt2[26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s1, s2; cin >> s1 >> s2;
  for (char c : s1)
    cnt1[c - 'a']++;
  for (char c : s2)
    cnt2[c - 'a']++;
  for (int i = 0; i < 26; i++) {
    cnt[i] = max(cnt1[i], cnt2[i]);
  }

  for (char c = 'a'; c <= 'z'; c++) {
    if (!cnt[c - 'a']) continue;
    while (cnt[c - 'a']--)
      cout << c;
  }
}
