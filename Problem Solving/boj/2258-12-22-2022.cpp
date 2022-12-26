#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 0x7f7f7f7f7f;

int n, m;
vector<pair<int, int>> meat; // {price, weight}

bool cmp(pair<int, int> a, pair<int, int> b) {
  if(a.first != b.first) return a.first < b.first;
  else return a.second > b.second;
}

int solve() {
  ll ans = INF;
  int mxprice = 0, totpr = 0, totwei = 0;
  for(auto [price, weight] : meat) {
    if(mxprice < price) {
      mxprice = price;
      totpr = mxprice;
    } else totpr += price;
    totwei += weight;
    if(totwei >= m) ans = min(ans, (ll)totpr);
  }
  if(ans == INF) return -1;
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  while(n--) {
    int weight, price;
    cin >> weight >> price;
    meat.push_back({price, weight});
  }
  sort(meat.begin(), meat.end(), cmp);

  cout << solve() << '\n';
}