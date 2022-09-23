#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int p[1002];
int ans;

vector<tuple<int, int, int>> e;

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool areindiffgr(int x, int y) {
  x = find(x), y = find(y);
  if(x == y) return 0;
  if(p[x] == p[y]) p[x]--;
  if(p[x] < p[y]) p[y] = x;
  else p[x] = y;
  return 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  fill(p, p + n + 1, -1);

  int cnt = 0;
  while(k--) {
    int x; cin >> x;
    areindiffgr(0, x);
    cnt++;
  }

  int x, y, cost;
  for(int i = 0; i < m; i++) {
    cin >> x >> y >> cost;
    e.push_back({cost, x, y});
  }

  sort(e.begin(), e.end());

  auto it = e.begin();
  while(cnt < n) {
    tie(cost, x, y) = *it; it++;
    if(!areindiffgr(x, y)) continue;
    cnt++;
    ans += cost;
  }
  cout << ans;
}