#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;

int n, s, m, v[MX + 2];
int ans = -1;

int main() {
  cin >> n >> s >> m;
  for(int i = 0; i < n; i++)
    cin >> v[i];
  
  set<int> cs, ns;
  cs.insert(s);
  int cur = 0;
  do {
    for(int cv : cs) {
      for(int dv : {-v[cur], v[cur]}) {
        dv += cv;
        if(dv < 0 || dv > m) continue;
        ns.insert(dv);
      }
    }
    cs = ns; ns.clear();
    if(cs.size() == 0) break;
  } while(++cur < n);

  if(cur == n)
    for(int v : cs) 
      ans = max(v, ans);

  cout << ans;
}