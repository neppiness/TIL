#include <bits/stdc++.h>
using namespace std;

int a[5];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int mx = -1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[j];
    }
    vector<bool> comb = {0, 0, 1, 1, 1};
    int mx_sum = 0;

    do {
      int sum = 0;
      for (int i = 0; i < 5; i++) {
        if(comb[i]) sum += a[i];
      }
      sum %= 10;
      mx_sum = max(mx_sum, sum);
    } while (next_permutation(comb.begin(), comb.end()));

    if (mx <= mx_sum) {
      mx = mx_sum;
      ans = i;
    }
  }
  cout << ans;
}
