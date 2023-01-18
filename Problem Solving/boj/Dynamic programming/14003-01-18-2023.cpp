#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MX = 1'000'000;

int ile[MX + 2]; // index of last element, indexed by LIS len.
int a[MX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(ile + 1, ile + MX + 2, INF);
  ile[0] = 0; a[0] = -INF;

  int n; cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  
  for(int i = 1; i <= n; i++) {
    int len = lower_bound(ile, ile + n + 1, i) - ile;
    if(a[ile[len - 1]] < a[i]) ile[len] = i;
    else ile[len - 1] = i;
  }
  int ans = lower_bound(ile, ile + n + 2, INF) - ile - 1;
  cout << ans << '\n';
}