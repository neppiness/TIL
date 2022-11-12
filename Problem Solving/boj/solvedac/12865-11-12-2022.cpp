#include <bits/stdc++.h>
using namespace std;

const int MX = 100'002;

vector<int> tochk;
vector<pair<int,int>> item;
int tot[MX];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, limit;
  cin >> n >> limit;

  fill(tot + 1, tot + MX, -1);
  tochk.push_back(0);

  int w, v;
  for(int i = 0; i < n; i++) {
    cin >> w >> v;
    item.push_back({w, v});
  }
  sort(item.begin(), item.end());
  
  for(auto [w, v] : item) {
    if(w > limit) continue;
    int tcsz = tochk.size();
    for(int i = 0; i < tcsz; i++) {
      int tc = tochk[i];
      if(tc + w > limit) continue;
      if(tot[tc + w] == -1) tochk.push_back(tc + w);
      tot[tc + w] = max(tot[tc + w], tot[tc] + v);
    }
  }
  int mxidx = max_element(tot, tot + limit + 1) - tot;
  cout << tot[mxidx];
}