#include <bits/stdc++.h>
using namespace std;

const int MX = 200'000;

unordered_map<string, int> nametoid;
int unused, p[MX + 2];


int find(int cur) {
  if(p[cur] < 0) return cur;
  return p[cur] = find(p[cur]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return;
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
    for(int i = 0; i < 2; i++) {
      cin >> a[i];
      if(nametoid.find(a[i]) == nametoid.end())
        nametoid[a[i]] = unused++;
    }
    int u = nametoid[a[0]];
    int v = nametoid[a[1]];
    merge(u, v);
    cout << - p[find(u)] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}