#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 1'300'000;

vector<int> pr;
vector<bool> is_pr(MX + 2, 1);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  is_pr[0] = is_pr[1] = 0;

  for (int i = 2; i <= MX; i++) {
    if (!is_pr[i]) continue;
    for (int j = i; (ll)j * i <= MX; j++)
      is_pr[j * i] = 0;
  }
  for (int i = 0; i <= MX; i++) 
    if (is_pr[i]) pr.push_back(i);

  int t; cin >> t;
  while (t--) {
    int x; cin >> x;
    auto ub = lower_bound(pr.begin(), pr.end(), x);
    auto lb = ub; lb--;
    if (*ub == x) cout << 0 << '\n';
    else cout << *ub - *lb << '\n';
  }
}