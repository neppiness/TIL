#include <bits/stdc++.h>
using namespace std;

int n;
int par[302];
bool w[302]; // is watered or not
vector<tuple<int, int, int>> p;

int find(int x) {
  if(par[x] < 0) return x;
  return par[x] = find(par[x]);
}

bool areindiffgr(int a, int b) {
  a = find(a); b = find(b);
  if(a == b) return 0;
  if(par[a] == par[b]) par[a]--;
  if(par[a] < par[b]) par[b] = a;
  else par[a] = b;
  w[b] = (w[a] || w[b]);
  w[a] = (w[a] || w[b]);
  return 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int cost;
  for(int i = 0; i < n; i++) {
    cin >> cost;
    p.push_back({cost, i, i});
  }
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> cost;
      if(i == j) continue;
      else p.push_back({cost, i, j});
    }
  
  fill(par, par + n, -1);
  sort(p.begin(), p.end());

  int cnt = 0;
  int u, v, ru, rv;
  int ans = 0;
  auto cur = p.begin();

  while(cnt != n) {
    tie(cost, u, v) = *cur;
    cur++;

    ru = find(u);
    rv = find(v);

    if(u == v) {
      if(w[ru]) continue;
      else w[ru] = 1;
    } else if(u != v) {
      if((w[ru] == 1) && (w[rv] == 1)) continue;
      if(!areindiffgr(u, v)) continue;
    }
    cnt++;
    ans += cost;
  }
  cout << ans;
}