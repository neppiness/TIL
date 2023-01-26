#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MX = 100'000;

int p[MX + 2]; 
pair<int, int> x[MX + 2];
pair<int, int> y[MX + 2];
pair<int, int> z[MX + 2];

vector<tuple<int, int, int>> e; // e = {cost, u, v};

int find(int cur) {
  if(p[cur] < 0) return cur;
  return p[cur] = find(p[cur]);
}

bool is_diff_group(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return 0;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(p, p + MX + 2, -1);
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int cx, cy, cz;
    cin >> cx >> cy >> cz;
    x[i] = {cx, i};
    y[i] = {cy, i};
    z[i] = {cz, i};
  }
  
  sort(x, x + n);
  sort(y, y + n);
  sort(z, z + n);

  for(int i = 1; i < n; i++) {
    e.push_back({abs(x[i - 1].X - x[i].X), x[i - 1].Y, x[i].Y});
    e.push_back({abs(y[i - 1].X - y[i].X), y[i - 1].Y, y[i].Y});
    e.push_back({abs(z[i - 1].X - z[i].X), z[i - 1].Y, z[i].Y});
  }
  
  sort(e.begin(), e.end());

  int cnt = 0, sum = 0;
  for(auto [cost, u, v] : e) {
    if(!is_diff_group(u, v)) continue;
    sum += cost;
    cnt++;
    if(cnt == n - 1) break;
  }
  cout << sum;
}
