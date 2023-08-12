#include <bits/stdc++.h>
using namespace std;

struct Planet { int cx, cy, r; };

void solve() {
  vector<Planet> pv;

  int x[2], y[2];
  for(int i = 0; i < 2; i++)
    cin >> x[i] >> y[i];

  int n; cin >> n;
  while(n--) {
    Planet p;
    cin >> p.cx >> p.cy >> p.r;
    pv.push_back(p);
  }

  set<int> a;
  for(int i = 0; i < pv.size(); i++) {
    Planet &p = pv[i];
    bool isincluded[2] = {};
    for(int j = 0; j < 2; j++) {
      int lv = (x[j] - p.cx) * (x[j] - p.cx);
      lv += (y[j] - p.cy) * (y[j] - p.cy);
      int rv = (p.r) * (p.r);
      if(lv < rv) isincluded[j] = 1;
    }
    if(isincluded[0] && isincluded[1]) continue;
    if(!isincluded[0] && !isincluded[1]) continue;
    if(isincluded[0] || isincluded[1]) a.insert(i);
  }
  cout << a.size() << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}