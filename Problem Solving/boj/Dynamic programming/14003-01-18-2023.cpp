#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MX = 1'000'000;

int lel[MX + 2]; // last element of LIS, indexed by LIS len.
int a[MX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(lel + 1, lel + MX + 2, INF);
  lel[0] = -1, lel[1] = 0;

  int n; cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  for(int i = 0; i < n; i++) {
    int *cur = lower_bound(lel, lel + n + 1, a[i]);
    
  }
}
