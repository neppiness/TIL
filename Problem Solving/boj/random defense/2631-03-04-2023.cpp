#include <bits/stdc++.h>
using namespace std;

const int MX = 200 + 2;

int cache[MX], n;
vector<int> a;

int calc(int idx) {
  int &ret = cache[idx];
  if(ret != -1) return ret;

  ret = 1;

  for(int i = 0; i < idx; i++)
    if(a[i] < a[idx])
      ret = max(calc(i) + 1, ret);
  return ret;
}

int solve() {
  int ans = 0;
  for(int i = 0; i < n; i++)
    ans = max(calc(i), ans);
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  int ans = solve();
  cout << n - ans;
}