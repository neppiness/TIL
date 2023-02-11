#include <bits/stdc++.h>
using namespace std;

const int MX = 1000 + 2;
const int MMX = MX / 2 * MX + 2;

int t, n, m;
int a[MX], b[MX];
int psa[MMX], psb[MMX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  cin >> m;
  for(int i = 1; i <= m; i++) {
    cin >> b[i];
    b[i] += b[i - 1];
  }
  
  int cnta = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < i; j++) {
      psa[cnta] = a[i] - a[j];
      cnta++;
    }
  int cntb = 0;
  for(int i = 1; i <= m; i++)
    for(int j = 0; j < i; j++) {
      psb[cntb] = b[i] - b[j];
      cntb++;
    }
  sort(psa, psa + cnta);
  sort(psb, psb + cntb);

  long long ans = 0;
  for(int i = 0; i < cnta; i++) {
    auto eq = equal_range(psb, psb + cntb, t - psa[i]);
    ans += eq.second - eq.first;
  }
  cout << ans;
}