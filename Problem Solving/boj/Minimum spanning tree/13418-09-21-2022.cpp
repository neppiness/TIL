#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[1002];
vector<tuple<int,int,int>> e;

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool areindiffgr(int a, int b) {
  a = find(a), b = find(b);
  if(a == b) return 0;
  if(p[a] == p[b]) p[a]--;
  if(p[a] < p[b]) p[b] = a;
  else p[a] = b;
  return 1;
}

int solve() {
  fill(p, p + n + 1, -1);
  int cnt = 0, ans = 0;
  auto it = e.begin();

  while(cnt < n - 1) {
    int a, b, cost;
    auto cur = *it; it++;
    tie(cost, a, b) = cur;
    if(!areindiffgr(a, b)) continue;
    ans += cost;
    cnt++;
  }
  return ans*ans;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  n++; m++;
  
  while(m--) {
    int a, b, cost;
    cin >> a >> b >> cost;
    e.push_back({cost, a, b});
  }
  sort(e.rbegin(), e.rend());
  int ans = solve();

  sort(e.begin(), e.end());
  ans -= solve();

  cout << ans;
}