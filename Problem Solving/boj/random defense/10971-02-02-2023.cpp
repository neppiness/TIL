#include <bits/stdc++.h>
using namespace std;

const int MX = 10;

int n, ans = 0x7f7f7f7f;
int cost[MX + 2][MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> cost[i][j];

  vector<int> perm;
  for(int i = 0; i < n; i++)
    perm.push_back(i);
  
  do {
    int tot = 0;
    bool isvalid = 1;
    for(int cur = 0; cur < n; cur++) {
      int nxt = cur + 1;
      if(nxt == n) nxt = 0;
      int dc = cost[perm[cur]][perm[nxt]];
      if(!dc) { isvalid = 0; break; }
      tot += dc;
    }
    if(!isvalid) continue;
    ans = min(ans, tot);
  } while(next_permutation(perm.begin(), perm.end()));
  cout << ans;
}