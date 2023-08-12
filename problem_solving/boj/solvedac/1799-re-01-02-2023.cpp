#include <bits/stdc++.h>
using namespace std;

int n; 
vector<bool> comb;
vector<pair<int, int>> bs;

bool mn[22], ps[22];

void init(int lv) {
  comb.clear();
  for(int i = 0; i < bs.size() - lv; i++)
    comb.push_back(0);
  for(int i = 0; i < lv; i++)
    comb.push_back(1);
}

bool setbs() {
  fill(ps, ps + 22, 0);
  fill(mn, mn + 22, 0);
  for(int i = 0; i < bs.size(); i++) {
    if(!comb[i]) continue;
    auto [x, y] = bs[i];
    if(ps[x + y]) return 0;
    if(mn[10 + x - y]) return 0;
    ps[x + y] = 1;
    mn[10 + x - y] = 1;
  }
  return 1;
}

bool solve(int lv) {
  init(lv);
  do { if(setbs()) return 1; }
  while(next_permutation(comb.begin(), comb.end()));
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      bool x; cin >> x;
      if(x) bs.push_back({i, j});
    }

  int st = 0, en = bs.size();
  while(st < en) {
    int mid = (st + en) / 2 + 1;
    if(!solve(mid)) en = mid - 1;
    else st = mid;
  }
  cout << st;
}