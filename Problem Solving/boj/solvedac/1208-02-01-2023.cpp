#include <bits/stdc++.h>
using namespace std;

int n, s;
long long ans;

int sz[2];
vector<int> a[2], sa[2];

void setup(int idx) {
  vector<bool> comb(sz[idx], 0);
  for(int i = 0; i <= sz[idx]; i++) {
    if(i != 0) comb[sz[idx] - i] = 1;
    do {
      int sum = 0;
      for(int j = 0; j < sz[idx]; j++)
        if(comb[j]) sum += a[idx][j];
      sa[idx].push_back(sum); 
    } while(next_permutation(comb.begin(), comb.end()));
  }
  sort(sa[idx].begin(), sa[idx].end());
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  sz[0] = n / 2;
  sz[1] = n - sz[0];

  for(int i = 0; i < 2; i++)
    for(int j = 0; j < sz[i]; j++) {
      int x; cin >> x;
      a[i].push_back(x);
    }

  for(int i = 0; i < 2; i++)
    setup(i);

  for(auto x : sa[0]) {
    auto lb = lower_bound(sa[1].begin(), sa[1].end(), -x);
    auto ub = upper_bound(sa[1].begin(), sa[1].end(), -x);
    ans += ub - lb;
  }
  if(s == 0) ans--;
  cout << ans;
}
