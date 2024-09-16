#include <bits/stdc++.h>
using namespace std;

int cnt[26];

char trans(char c, int d) {
  if (c == ' ') return c;
  char cc = c - d;
  if (cc >= 'A') return cc;
  return cc + 'Z' - 'A' + 1;
}

bool is_solved(string &s, int d) {
  memset(cnt, 0, sizeof(cnt));

  for (char &c : s) {
    if (c == ' ') continue;
    cnt[trans(c, d) - 'A']++;
  }     
  int cnt_e = cnt[4];
  for (int i = 0; i < 26; i++) {
    if (i == 4) continue;
    if (cnt_e <= cnt[i]) return 0;
  }
  return 1;
}

void print(string &s, int d) {
  cout << d << ' ';
  for (char &c : s) cout << trans(c, d);
  cout << '\n';
}

bool solve(string &s) {
  for (int d = 0; d < 26; d++) {
    if (!is_solved(s, d)) continue;
    print(s, d);
    return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cin.ignore();

  for (int i = 0; i < n; i++) {
    string s; getline(cin, s);
    if (!solve(s))
      cout << "NOT POSSIBLE" << '\n';
  }
}
