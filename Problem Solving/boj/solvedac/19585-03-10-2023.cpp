#include <bits/stdc++.h>
using namespace std;

const int MX = 4000 * 1000;
const int ROOT = 1;

string s;

int unused = 2;
int trie[MX + 2][26];
int chk[MX + 2];

int ctoi(char c) { return c - 'a'; }

int insert(string &s, bool code) {
  int cur = ROOT;
  for(char c : s) {
    int &nxt = trie[cur][ctoi(c)];
    if(nxt == -1) nxt = unused++;
    cur = nxt;
  }
  chk[cur] = code;
}

bool solve() {
  cin >> s;
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(chk, -1, sizeof(chk));

  int c, n; cin >> c >> n;
  while(c--) { cin >> s; insert(s, 0); }
  while(n--) { cin >> s; insert(s, 1); }
  cin >> n;
  while(n--) {
    if(solve()) cout << "Yes\n";
    else cout << "No\n";
  }
}