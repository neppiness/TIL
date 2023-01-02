#include <bits/stdc++.h>
using namespace std;

const int NMX = 502;

int n, ans;
int ps[NMX];
bool op[NMX];

void solve() {
  return;
}

void init() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ps[i];
    ps[i] += ps[i - 1];
  }
  ans = 0;
}

void print() {
  for(int i = 0; i <= n; i++)
    cout << ps[i]<< ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    init();
    solve();
    print();
    cout << ans << '\n';
  }
}