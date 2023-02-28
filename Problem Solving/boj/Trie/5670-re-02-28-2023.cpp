#include <bits/stdc++.h>
using namespace std;

const int MX = 1e+6 + 2;
const int ROOT = 1;

int unused;
vector<pair<int, char>> trie[MX]; // trie[cur] = {nxt_node_no, char_id}
int cnt[MX];

int find(int cur, char cc) {
  for(auto [nxt, nc] : trie[cur])
    if(cc == nc) return nxt;
  return -1;
}

void insert(const string &s) {
  int cur = ROOT;
  for(char c : s) {
    int nxt = find(cur, c);
    if(nxt == -1) {
      nxt = unused++;
      trie[cur].push_back({nxt, c});
    }
    cnt[nxt]++;
    cur = nxt;
  }
}

int bfs(int cur) {
  int sum = 0;
  for(auto [nxt, nc] : trie[cur]) {
    if(cnt[cur] != cnt[nxt]) sum += cnt[nxt];
    sum += bfs(nxt);
  }
  return sum;
}

int trav() {
  int ans = 0;
  for(auto [nxt, nc] : trie[ROOT]) {
    ans += cnt[nxt];
    ans += bfs(nxt);
  }
  return ans;
}

void solve(int n) {
  for(int i = 0; i < MX; i++) trie[i].clear();
  memset(cnt, 0, sizeof(cnt));
  
  unused = 2;

  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    insert(s);
  }

  int ans = trav();
  cout << (double)ans / n << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(2);
  cout << fixed;

  int n;
  while(cin >> n) solve(n);
}