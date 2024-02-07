#include <bits/stdc++.h>
using namespace std;

const int MX = 20 * 1000 * 2 + 2;
const int ROOT = 1;

int n, unused;
vector<pair<char, int>> trie[MX]; // trie[cur] = {char, nxt}
bool is_wc_app[MX]; // is wild card applicable
bool chk[MX]; // should be removed

int find(char c, int cur) {
  for(auto [d, nxt] : trie[cur])
    if(c == d) return nxt;
  return -1;
}

void insert(string &s, bool code) {
  int cur = ROOT;
  is_wc_app[ROOT] = code;
  for(char c : s) {
    int nxt = find(c, cur);
    if(nxt == -1) {
      nxt = unused;
      trie[cur].push_back({c, unused++});
    }
    is_wc_app[nxt] = code;
    cur = nxt;
  }
  if(code) chk[cur] = code;
}

int search(int cur) {
  if(is_wc_app[cur]) return 1;

  int res = chk[cur];
  for(auto [c, nxt] : trie[cur])
    res += search(nxt);
  return res;
}

void solve() {
  fill(is_wc_app, is_wc_app + MX, 0);
  fill(chk, chk + MX, 0);
  unused = 2;

  for(int i = ROOT; i < MX; i++)
    trie[i].clear();
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    insert(s, 1);
  }
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    insert(s, 0);
  }
  int ans = search(ROOT);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}