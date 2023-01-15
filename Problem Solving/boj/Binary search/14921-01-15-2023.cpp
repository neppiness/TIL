#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int mn = INF, ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a;

  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  for(int i = 0; i < n; i++) {
    int idx = lower_bound(a.begin(), a.end(), - a[i]) - a.begin();
    for(int j = idx - 1; j <= idx + 1; j++) {
      if(j >= n || j < 0) continue;
      if(j == i) continue;
      int sum = a[i] + a[j];
      if(abs(sum) >= mn) continue;
      mn = abs(sum);
      ans = sum;
    }
  }
  cout << ans;
}