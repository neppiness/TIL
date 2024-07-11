#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a[9];
  for (int i = 0; i < 9; i++)
    cin >> a[i];

  bool comb[9] = {0, 0, 1, 1, 1, 1, 1, 1, 1};
  do {
    int sum = 0;
    for (int i = 0; i < 9; i++)
      if (comb[i]) sum += a[i];
    if (sum != 100) continue;
    vector<int> ans;
    for (int i = 0; i < 9; i++)
      if (comb[i]) ans.push_back(a[i]);
    sort(ans.begin(), ans.end());
    for (int x : ans) {
      cout << x << '\n';
    }
    return 0;
  } while (next_permutation(comb, comb + 9));
}
