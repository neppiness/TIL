#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> bp;
bool b[12][12];
bool pos[22], neg[22];

int mx;

void setbs(int x, int y, bool code) {
  neg[y - x + 10] = code;
  pos[y + x] = code;
} 

bool isoccupied(int x, int y) {
  return (neg[y - x + 10] || pos[y + x]);
}

void solve(int lv) {
  mx = max(mx, lv + 1);

  for(int i = lv + 1; i < bp.size(); i++) {
    auto [x, y] = bp[i];
    if(isoccupied(x, y)) continue;
    setbs(x, y, 1);
    solve(lv + 1);
    setbs(x, y, 0);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> b[i][j];
      if(!b[i][j]) continue;
      bp.push_back({i, j});
    }

  solve(-1);

  cout << mx;
}