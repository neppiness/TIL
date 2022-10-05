#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int, int>> coord;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int x, y;
  while(n--) {
    cin >> x >> y;
    coord.push_back({x, y});
  }
  sort(coord.begin(), coord.end());
  for(auto c : coord) {
    tie(x, y) = c;
    cout << x << ' ' << y << '\n';
  }
}