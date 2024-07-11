#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k; 
ll dist[100'002];

int solve() {
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += dist[i];
    if (sum > k) return i;
  }
  for (int i = n; i >= 1; i--) {
    sum += dist[i];
    if (sum > k) return i;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
    cin >> dist[i];

  cout << solve();
}
