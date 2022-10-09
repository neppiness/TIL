#include <bits/stdc++.h>
using namespace std;

int a[500'002];
int cnt[8002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(0);
  cout << fixed;

  int sum = 0;
  int m = 0x7f7f7f7f, M = -0x7f7f7f7f;

  int Mcnt = 0;
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    M = max(M, a[i]);
    m = min(m, a[i]);
    sum += a[i];
    cnt[a[i] + 4000]++;
    Mcnt = max(Mcnt, cnt[a[i] + 4000]);
  }


  cout << floor((double)sum / (double)n + 0.5) << '\n';

  sort(a, a + n);
  int midx = n/2;

  cout << a[midx] << '\n';

  vector<int> fr;
  for(int i = 0; i < 8002; i++)
    if(cnt[i] == Mcnt)
      fr.push_back(i - 4000);
  if(fr.size() > 1) cout << fr[1] << '\n';
  else cout << fr[0] << '\n';

  cout << M - m;
}