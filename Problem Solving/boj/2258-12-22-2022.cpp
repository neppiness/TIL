#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> v; // {cost, value}
vector<tuple<int, int, int>> ps; // {cost, value sum for less or equal, value sum for greater}

bool cmp(pair<int, int> a, pair<int, int> b) {
  if(a.first != b.first) return a.first < b.first;
  else return a.second > b.second;
}

int solve() {
  ps.push_back({0, 0, 0});
  for(int i = 0; i < v.size(); i++) {
    auto [cost, value] = v[i];
    int cur = ps.size() - 1;
    auto [d, leqval, gval] = ps[cur];
    if(d != cost) {
      leqval = gval + value;
      ps.push_back({cost, leqval, leqval});
    } else {
      gval += value;
      ps[cur] = {d, leqval, gval};
    }

    if(leqval >= m) return cost;
    else if(gval >= m) return cost + 1;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  while(n--) {
    int value, cost;
    cin >> value >> cost;
    v.push_back({cost, value});
  }
  sort(v.begin(), v.end(), cmp);

  cout << solve() << '\n';
}