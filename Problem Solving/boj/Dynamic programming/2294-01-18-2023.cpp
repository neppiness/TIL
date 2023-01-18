#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int n, k;
int coin[100], cnt[10'002];

void solve(int cur) {
  for(int i = 0; i < n; i++) {
    int prv = cur - coin[i];
    if(prv < 0) continue;
    if(cnt[prv] == -1) continue;
    cnt[cur] = min(cnt[cur], cnt[prv] + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(cnt, cnt + 10'002, INF);
  cnt[0] = 0;

  cin >> n >> k;

  for(int i = 0; i < n; i++) cin >> coin[i];
  for(int i = 1; i <= k; i++) solve(i);

  if(cnt[k] == INF) cnt[k] = -1;
  cout << cnt[k];
}