#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int NMX = 502;
const ll INF = 0x7f7f7f7f7f;

ll cache[NMX][NMX];
int n, page[NMX], ps[NMX];

ll solve(int st, int en) {
  if(st == en) return 0;
  ll &ret = cache[st][en];
  if(ret != -1) return ret;

  ll ans = INF;
  for(int i = st; i < en; i++)
    ans = min(ans, solve(st, i) + solve(i + 1, en));
  ans += ps[en + 1] - ps[st];
  return ret = ans;
}

void init() {
  memset(cache, -1, sizeof(cache));
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> page[i];
    ps[i + 1] = ps[i] + page[i]; 
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    init();
    cout << solve(0, n - 1) << '\n';
  }
}