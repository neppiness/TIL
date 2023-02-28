#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; i++)
    if(n % i == 0) ans.push_back(i);
  if(ans.size() < k) cout << 0;
  else cout << ans[k - 1];
}