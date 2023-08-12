#include <bits/stdc++.h>
using namespace std;

const int MX = 3'000 + 2;

int p[MX], n;
bool is_par[MX];

struct vec {
  double x, y;
  explicit vec(double x_ = 0, double y_ = 0): x(x_), y(y_) {}
  
  double cross(vec &r) { return (x * r.y - y * r.x); }

  bool operator < (vec &r) { return (x != r.x ? x < r.x : y < r.y); }
  vec operator - (vec &r) { return (vec(x - r.x, y - r.y)); }
} vecs[MX][2];

double ccw(vec p, vec q, vec r) { return (p.cross(q) * p.cross(r)); }

bool chk_ccw(int u, int v) {
  vec &a = vecs[u][0]; vec &b = vecs[u][1];
  vec &c = vecs[v][0]; vec &d = vecs[v][1];
  double ccw1 = ccw(b - a, c - b, d - b);
  double ccw2 = ccw(d - c, a - d, b - d);
  if(ccw1 > 0 || ccw2 > 0) return 0;
  if(ccw1 == 0 && ccw2 == 0)
    return !(b < c || d < a);
  return 1;
}

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  cin >> n;
  for(int i = 0; i < n; i++) {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vecs[i][0] = vec(x1, y1);
    vecs[i][1] = vec(x2, y2);
    if(vecs[i][1] < vecs[i][0])
      swap(vecs[i][0], vecs[i][1]);
  }

  for(int i = 1; i < n; i++)
    for(int j = 0; j < i; j++)
      if(chk_ccw(i, j)) merge(i, j);

  int cnt = 0, mx = 0;
  for(int i = 0; i < n; i++) {
    int pi = find(i);
    if(is_par[pi]) continue;
    is_par[pi] = 1;
    cnt++;
    mx = max(mx, -p[pi]);
  }
  cout << cnt << '\n' << mx;
}