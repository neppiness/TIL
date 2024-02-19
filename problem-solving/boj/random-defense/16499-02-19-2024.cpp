#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> chk;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    int cnt[26] = {};
    string s; cin >> s;
    for (char c : s) cnt[c - 'a']++;
    s = "";
    for (int i = 0; i < 26; i++) {
      s += to_string(cnt[i]);
    }
    chk[s] = 1;
  }
  cout << chk.size();
}
