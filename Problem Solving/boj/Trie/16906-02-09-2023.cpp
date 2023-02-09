#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000 + 5;
const int ROOT = 1;

int n, unused = 2;

int nxt[MX][2];
int len[MX], sorted_len[MX];
bool chk[MX];

queue<string> ans[MX + 5];

bool ins(int L) {
  string s = "";
  int cur = ROOT;
  int l = L;
  while(l--) {
    bool is_inserted = 0;
    for(int i = 0; i < 2; i++) {
      int &nx = nxt[cur][i];
      if(nx == -1) nx = unused++;
      if(chk[nx]) continue;
      s += (char)(i + '0');
      is_inserted = 1;
      cur = nx;
      break;
    }
    if(!is_inserted) break;
  }
  if(l != -1) return 0;
  chk[cur] = 1;
  s += '\0';
  ans[L].push(s);
  return 1;
}

bool tryInsert() {
  bool valid_insert;
  for(int i = 0; i < n; i++) {
    valid_insert = ins(sorted_len[i]);
    if(!valid_insert) return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(nxt, -1, sizeof(nxt));

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> len[i];
    sorted_len[i] = len[i];
  }
  sort(sorted_len, sorted_len + n);

  if(!tryInsert()) {
    cout << - 1;
  } else {
    cout << 1 << '\n';
    for(int i = 0; i < n; i++) {
      cout << ans[len[i]].front() << '\n';
      ans[len[i]].pop();
    }
  }

  cout << '\n';
  for(int i = ROOT; i < 8; i++)
    cout << chk[i] << ' ';
}