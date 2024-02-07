#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
const string CC = "ChongChong";

unordered_map<string, int> nameToId;
int unused = 1, ans = 1;
int p[2*MX + 2]; // 총총이는 p[cc] < 0 나머지는 p[cc] = 0

int find(int cur) {
  if(p[cur] <= 0) return cur;
  return p[cur] = find(p[cur]);
}

void try_merge(int u, int v) {
  u = find(u), v = find(v);
  if(u == 1 && v == 1) return;
  if(u != 1 && v != 1) return;
  if(p[u] == 0) swap(u, v); // u는 반드시 총총이가 된다.
  p[v] = 1; ans++;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  nameToId[CC] = unused;
  p[unused++] = -1;

  int m; cin >> m;
  while(m--) {
    string a, b; cin >> a >> b;
    int& u = nameToId[a];
    if(u == 0) u = unused++;
    int& v = nameToId[b];
    if(v == 0) v = unused++;
    try_merge(u, v);
  }
  cout << ans;
}