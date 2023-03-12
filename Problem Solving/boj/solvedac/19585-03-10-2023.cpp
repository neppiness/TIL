#include <bits/stdc++.h>
using namespace std;

const int MX = 2 * 4000 * 1000;
const int ROOT = 1;

int unused = 2;
int trie[MX + 2][26];

// word type, -1 for nothing, 0 for color, 1 for nickname and 2 for both
int chk[MX + 2];

__inline int ctoi(char c) { return c - 'a'; }

void insert(int code) {
  string s; cin >> s;
  int cur = ROOT;
  for(char c : s) {
    int &nxt = trie[cur][ctoi(c)];
    if(nxt == -1) nxt = unused++;
    cur = nxt;
  }
  if(chk[cur] != -1) chk[cur] = 2;
  else chk[cur] = code;
}

vector<int> find_color_idx(string &s) {
  vector<int> v;
  int cur = ROOT;
  for(int i = 0; i < s.size(); i++) {
    int &nxt = trie[cur][ctoi(s[i])];
    if(nxt == -1) return v;
    if(chk[nxt] == 0 || chk[nxt] == 2) v.push_back(i + 1);
    cur = nxt;
  }
  return v;
}

bool solve() {
  string s; cin >> s;
  vector<int> found_idx = find_color_idx(s);

  for(int idx : found_idx) {
    bool is_found = 1;
    int cur = ROOT;
    for(; idx < s.size(); idx++) {
      int nxt = trie[cur][ctoi(s[idx])];
      if(nxt == -1) { is_found = 0; break; }
      cur = nxt;
    }
    if(is_found && chk[cur] >= 1) return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(chk, -1, sizeof(chk));
  memset(trie, -1, sizeof(trie));

  int c, n; cin >> c >> n;
  while(c--) insert(0);
  while(n--) insert(1);

  cin >> n;
  while(n--) {
    if(solve()) cout << "Yes\n";
    else cout << "No\n";
  }
}