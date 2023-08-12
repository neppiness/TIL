#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000;
int p[MX + 2];
bool vis[MX + 2];

void trav(int cur) {
  vis[cur] = 1;
  if(p[cur] == -1) return;
  trav(p[cur]);
}

int find(int cur) {
  if(vis[cur]) return cur;
  return find(p[cur]);
}

void solve() {
  memset(p, -1, sizeof(p));
  memset(vis, 0, sizeof(vis));

  int n; cin >> n;
  int a, b;
  while(--n) {
    cin >> a >> b;
    p[b] = a;
  }
  cin >> a >> b;
  trav(a);
  cout << find(b) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}