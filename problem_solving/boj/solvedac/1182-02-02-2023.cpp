#include <bits/stdc++.h>
using namespace std;

int n, s, ans;

int sz[2];
vector<int> a;

void solve() {
  vector<bool> comb(n, 0);
  for(int i = 1; i <= n; i++) {
    comb[n - i] = 1;
    do {
      int sum = 0;
      for(int j = 0; j < n; j++)
        if(comb[j]) sum += a[j];
      if(sum == s) ans++;
    } while(next_permutation(comb.begin(), comb.end()));
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    a.push_back(x);
  }
  solve();
  cout << ans;
}
