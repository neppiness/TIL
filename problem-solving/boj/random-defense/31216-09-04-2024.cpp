#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_pr[320'002];
vector<int> pr, spr;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(is_pr, is_pr + 320'002, 1);
  is_pr[1] = 0;

  for (ll i = 2; i <= 320'000; i++) {
    if (!is_pr[i]) continue;
    for (ll j = i; j * i <= 320'000; j++) {
      is_pr[i * j] = 0;
    }
  }

  for (int i = 2; i <= 320'000; i++)
    if (is_pr[i]) pr.push_back(i);

  for (int p : pr) {
    if (spr.size() == 3000) break;
    spr.push_back(pr[p - 1]);
  }

  int n; cin >> n;
  while (n--) {
    int x; cin >> x;
    cout << spr[x - 1] << '\n';
  }
}
