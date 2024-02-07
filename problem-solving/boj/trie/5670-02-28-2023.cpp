#include <bits/stdc++.h>
using namespace std;

const int MX = 1e+6 + 2;
const int ROOT = 1;

int unused;
int trie[MX][26], cnt[MX];
bool chk[MX];

int ctoi(char c) { return c - 'a'; }

void insert(const string &s) {
  int cur = ROOT;
  for(char c : s) {
    int &nxt = trie[cur][ctoi(c)];
    if(nxt == -1) nxt = unused++;
    cnt[nxt]++;
    cur = nxt;
  }
  chk[cur] = 1;
}

int bfs(int cur) {
  int sum = 0;
  for(char c = 'a'; c <= 'z'; c++) {
    int &nxt = trie[cur][ctoi(c)];
    if(nxt == -1) continue;
    // 현재 이전 글자를 누른 상태이므로, 다음 글자를 눌러야 한다면 그 횟수를 추가하는 것.
    if(cnt[cur] != cnt[nxt]) sum += cnt[nxt];
    sum += bfs(nxt);
  }
  return sum;
}

int trav() {
  int ans = 0;
  for(char c = 'a'; c <= 'z'; c++) {
    int &nxt = trie[ROOT][ctoi(c)];
    if(nxt == -1) continue;
    ans += cnt[nxt];
    ans += bfs(nxt);
  }
  return ans;
}

void solve(int n) {
  memset(trie, -1, sizeof(trie));
  memset(chk, 0, sizeof(chk));
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