#include <bits/stdc++.h>
using namespace std;

const int NMX = 10'000;
const int MMX = 100;

int ans;
vector<int> ori[MMX + 2]; // original univ.
vector<int> sor[MMX + 2]; // sorted univ.

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m; cin >> n >> m;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      int x; cin >> x;
      ori[i].push_back(x);
      sor[i].push_back(x);
    }
  
  for(int i = 0; i < n; i++)
    sort(sor[i].begin(), sor[i].end());
  
  // erase dupliated univ.
  for(int i = 1; i < n; i++)
    for(int j = 0; j < i; j++)
      if(sor[i] == sor[j])
        ori[j][0] = -1;

  for(int i = 0; i < n; i++) {
    if(ori[i][0] == -1) { continue; }
    for(int j = 0; j < m; j++)
      ori[i][j] = lower_bound(sor[i].begin(), sor[i].end(), ori[i][j]) - sor[i].begin();
  }

  sort(ori, ori + n);

  int cnt = 1;
  for(int i = 1; i < n; i++) {
    if(ori[i][0] == -1) continue;
    if(ori[i] != ori[i - 1]) { ans += ((cnt - 1)*cnt)/2; cnt = 1; }
    else cnt++;
  }
  ans += ((cnt - 1)*cnt)/2;
  cout << ans;
}