#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> pr;
bool is_pr[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(is_pr, is_pr + 100'002, 1);
  is_pr[0] = 0;
  is_pr[1] = 0;
  for (ll i = 2; i <= 100'000; i++) {
    if (!is_pr[i]) continue;
    pr.push_back(i);
    for (ll j = i * i; j <= 100'000; j += i)
      is_pr[j] = 0;
  }

  int n, k; cin >> n >> k;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int mx_pr = 0;
    int idx = 0;
    int x = i;
    while (x != 1) {
      int p = pr[idx];
      if (x % p) {
        idx++;
        continue;
      }
      x /= p;
      mx_pr = max(mx_pr, p);
    }
    cnt += (mx_pr <= k);
  }
  cout << cnt;
}
