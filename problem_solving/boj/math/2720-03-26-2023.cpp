#include <bits/stdc++.h>
using namespace std;

int co[] = {25, 10, 5, 1};

void solve() {
  int x; cin >> x;
  for(int i = 0; i < 4; i++) {
    int no = x / co[i];
    cout << no << ' ';
    x -= co[i] * no;
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}