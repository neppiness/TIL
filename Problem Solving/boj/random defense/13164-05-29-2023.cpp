#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int diff[300'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int cur; cin >> cur;
  for (int i = 0; i < n - 1; i++) {
    int nxt; cin >> nxt;
    diff[i] = (nxt - cur);
    cur = nxt;
  }

  sort(diff, diff + n - 1);
  int pick = n - k;
  ll sum = 0;
  for (int i = 0; i < pick; i++) {
    sum += diff[i];
  }
  cout << sum;
}