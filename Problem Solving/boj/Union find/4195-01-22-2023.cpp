#include <bits/stdc++.h>
using namespace std;

const int MX = 200'000; // 친구관계 100,000에 주어지는 아이디가 2개이므로

int unused, p[MX + 2];
int trie[52][22]; // 알파벳 대소문자 26개 + 26개. 문자열 길이 20이하




int find(int cur) {
  if(p[cur] < 0) return cur;
  return p[cur] = find(p[cur]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

void solve() {
  nametoid.clear();
  unused = 1;
  memset(p, -1, sizeof(p));

  int n; cin >> n;
  string a[2];
  while(n--) {
    int u, v;
    for(int i = 0; i < 2; i++) {
      cin >> a[i];
      u[i] = trfind(a[i]);
      if(u[i] == -1) u[i] = tradd[a[i]];
    }
    merge(u[0], u[1]);
    cout << - p[find(u[0])] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}