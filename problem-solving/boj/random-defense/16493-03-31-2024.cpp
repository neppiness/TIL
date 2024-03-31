#include <bits/stdc++.h>
using namespace std;

int n, m, ans; 
int day[22], page[22];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> day[i] >> page[i];

  for (int i = 1; i <= m; i++) {
    vector<bool> comb;
    for (int j = 0; j < m - i; j++)
      comb.push_back(0);
    for (int j = 0; j < i; j++)
      comb.push_back(1);

    do {
      int spend_days = 0;
      int read_page = 0;
      for (int i = 0; i < m; i++) {
        if (!comb[i]) continue;
        spend_days += day[i];
        read_page += page[i];
      }
      if (spend_days <= n) ans = max(ans, read_page);
    } while (next_permutation(comb.begin(), comb.end()));
  }
  cout << ans;
}
