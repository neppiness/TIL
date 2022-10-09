#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int x, y;
  while(n--) {
    cin >> x >> y;
    v.push_back({y, x});
  }
  sort(v.begin(), v.end());
  for(auto cur : v)
    cout << cur.second << ' ' << cur.first << '\n';
}