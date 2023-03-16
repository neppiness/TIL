#include <bits/stdc++.h>
using namespace std;

const int MX = 20 * 1000 * 2;
const int ROOT = 1;

int n, unused, cnt;
vector<pair<char, int>> trie[MX + 2]; // trie[cur] = {char, nxt}
bool chk[MX + 2];

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
    chk[nxt] = code;
  }
}

void search(int cur) {
  bool is_checked = 0;
  for(auto [c, nxt] : trie[cur])
    if(chk[nxt]) { is_checked = 1; break; }

  if(!is_checked && !chk[cur]) { cnt++; return; }
  for(auto [c, nxt] : trie[cur])
    search(nxt);
}

void solve() {
  memset(chk, 0, sizeof(chk));
  unused = 2;
  cnt = 0;
  for(int i = ROOT; i < MX; i++)
    trie[i].clear();
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    insert(s, 0);
  }
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    insert(s, 1);
  }

  search(ROOT);
  cout << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}