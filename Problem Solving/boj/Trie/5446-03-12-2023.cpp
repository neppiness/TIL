#include <bits/stdc++.h>
using namespace std;

const int MX = 20 * 1000 * 2;
const int ROOT = 1;

int n, unused;
vector<pair<char, int>> trie[MX + 2]; // trie[cur] = {char, nxt}
bool is_wc_app[MX + 2]; // is wild card applicable?
bool term[MX + 2]; // should be removed?

int find(char c, int cur) {
  for(auto [d, nxt] : trie[cur])
    if(c == d) return nxt;
  return -1;
}

void insert(string &s, bool code) {
  int cur = ROOT;
  for(char c : s) {
    int nxt = find(c, cur);
    if(nxt == -1) { // -1: not_found
      nxt = unused;
      trie[cur].push_back({c, unused++});
    }
    is_wc_app[nxt] = code;
    cur = nxt;
  }
  term[cur] = code;
}

int search(int cur) {
  bool is_wc_app_at_nxt = 1;
  for(auto [c, nxt] : trie[cur])
    if(is_wc_app[nxt]) { is_wc_app_at_nxt = 0; break; }
  if(is_wc_app_at_nxt && !term[cur]) return 1;

  int res = 0;
  for(auto [c, nxt] : trie[cur]) {
    res += term[nxt];
    res += search(nxt);
  }
  return res;
}

void solve() {
  memset(is_wc_app, 0, sizeof(is_wc_app));
  memset(term, 0, sizeof(term));
  unused = 2;

  for(int i = ROOT; i < MX; i++)
    trie[i].clear();
  
  cin >> n;
  is_wc_app[ROOT] = 1;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    insert(s, 1);
  }
  cin >> n;
  if(n) is_wc_app[ROOT] = 0;
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