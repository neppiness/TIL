#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<pair<int, int>> v;
  for(int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    v.push_back({x, y});
  }

  int tot = 0;
  while(v.size() != 1) {
    int min = INF;
    auto tmp = v.begin() + 1;
    for(auto it = v.begin() + 1; it != v.end(); it++) {
      auto [ux, uy] = *(it - 1);
      auto [lx, ly] = *it;
      if(min > ux * ly) {
        min = ux * ly;
        tmp = it;
      }
    }
    auto [ux, uy] = *(tmp - 1);
    auto [lx, ly] = *tmp;
    tot += ux * uy * ly;
    (*(tmp - 1)).second = ly;
    v.erase(tmp);
  }
  cout << tot;
}