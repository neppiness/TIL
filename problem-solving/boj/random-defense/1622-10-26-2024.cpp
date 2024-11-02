#include <bits/stdc++.h>
using namespace std;

int cnt[2][26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  while (getline(cin, a)) {
    getline(cin, b);
    for (char c : a) cnt[0][c - 'a']++;
    for (char c : b) cnt[1][c - 'a']++;

    for (char c = 'a'; c <= 'z'; c++) {
      int cc = min(cnt[0][c - 'a'], cnt[1][c - 'a']);
      while (cc--) cout << c;
    }

    memset(cnt, 0, sizeof(cnt));
    cout << '\n';
  }
}
