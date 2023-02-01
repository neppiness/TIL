#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000'000;

int sz[2], n, lim, ans;
vector<int> a[2];
map<int, int> m[2];

void setup(int idx) {
  vector<bool> comb(sz[idx], 0);

  for(int i = sz[idx]; i >= 0; i--) {
    if(i != sz[idx]) comb[i] = 1;
    do {
      int cur = 0;
      bool isvalid = 1;
      for(int j = 0; j < (int)comb.size(); j++) {
        if(comb[j]) cur += a[idx][j];
        if(cur > MX) { isvalid = 0; break; }
      }
      if(isvalid) m[idx][cur]++;
    } while(next_permutation(comb.begin(), comb.end()));
  }
}

void solve() {
  int sum = 0;
  for(auto it = m[1].begin(); it != m[1].end(); it++)
    sum += (it -> second);

  auto it1 = m[1].rbegin();
  auto it0 = m[0].begin();
  while(it0 != m[0].end() && it1 != m[1].rend()) {
    int tot = (it0 -> first) + (it1 -> first);
    if(tot <= lim) {
      ans += (it0 -> second) * sum;
      it0++;
    } else {
      sum -= (it1 -> second);
      it1++;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> lim;
  sz[0] = n / 2;
  sz[1] = n - sz[0];

  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < sz[i]; j++) {
      int x; cin >> x;
      a[i].push_back(x);
    }
    sort(a[i].begin(), a[i].end());
  }
  
  for(int i = 0; i < 2; i++) setup(i);

  solve();
  cout << ans << '\n';
}
