#include <bits/stdc++.h>
using namespace std;

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

  int ans = 0;
  do {
    int tmp = 0;
    for(int i = 1; i < n; i++)
      tmp += abs(a[i] - a[i - 1]);
    ans = max(ans, tmp);
  } while(next_permutation(a.begin(), a.end()));

  cout << ans;
}