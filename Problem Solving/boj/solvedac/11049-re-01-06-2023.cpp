#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 0x7f7f7f7f7f;
const int NMX = 502;

// mt[code][idx]
// code: 0 for # of rows and 1 for # of cols
int mt[2][NMX];
int cache[NMX][NMX]; // cache[starting index][end index]
int n;

int solve(int st, int en) {
  // base case, # of mult. operations for A[st]×A[st + 1]
  if(st == en) return 0;
  
  int &ret = cache[st][en];
  if(ret != -1) return ret;

  ll ans = INF;
  for(int mid = st; mid < en; mid++) {
    ll tmp = solve(st, mid) + solve(mid + 1, en) + mt[0][st] * mt[1][mid] * mt[1][en];
    ans = min(ans, tmp);
  }
  return ret = ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> mt[0][i] >> mt[1][i];

  cout << solve(0, n - 1);
}
