#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int OPS_LIM = 1e8;
const int ABS_LIM = 1e9;

bool solve() {
  string comp;
  int n, t, l;
  cin >> comp >> n >> t >> l;

  ll tot = 1;
  if (comp.size() == 4) { // O (N)
    tot = n;
  } else if (comp.size() == 5) { // O (N!)
    if (n >= 13) return 0;
    for (int i = 2; i <= n; i++)
      tot *= i;
  } else if (comp[4] == '2') { // O (N^2)
    tot = (ll)n * n;
  } else if (comp[4] == '3') { // O (N^3)
    tot = (ll)n * n * n;
    if (tot > ABS_LIM) return 0;
  } else { // O (2^N)
    if (n >= 30) return 0;
    tot = (ll)1 << n;
  }
  return t * tot <= OPS_LIM * l; 
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    if (solve()) cout << "May Pass.\n";
    else cout << "TLE!\n";
  } 
}
