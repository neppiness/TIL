#include <bits/stdc++.h>
using namespace std;

int a[26];
string s;

char solve() {
  int midx = max_element(a, a + 26) - a;
  int c = s[midx];
  for(int i = 0; i < 26; i++) {
    if(i == midx) continue;
    else if(a[i] == a[midx]) return '?';
  }
  return midx + 'A';
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  for(char c : s) {
    if(c >= 'a' && c <= 'z') a[c - 'a']++;
    else if(c >= 'A' && c <= 'Z') a[c - 'A']++;
  }
  cout << solve();
}