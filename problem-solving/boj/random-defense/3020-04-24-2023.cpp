#include <bits/stdc++.h>
using namespace std;

vector<int> bt, tp; // bt: 석순, tp: 종유석
int n, h, cnt, mn = 0x7f7f7f7f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> h;
  bt.resize(n/2);
  tp.resize(n/2);
  for(int i = 0; i < n/2; i++)
    cin >> bt[i] >> tp[i];

  sort(bt.begin(), bt.end());
  sort(tp.begin(), tp.end());

  for(int x = 1; x <= h; x++) {
    int btcnt = bt.end() - lower_bound(bt.begin(), bt.end(), x);
    int tpcnt = tp.end() - lower_bound(tp.begin(), tp.end(), h + 1 - x);
    if(mn < btcnt + tpcnt) continue;
    if(mn == btcnt + tpcnt) cnt++;
    else { cnt = 1; mn = btcnt + tpcnt; }
  }

  cout << mn << ' ' << cnt;
}