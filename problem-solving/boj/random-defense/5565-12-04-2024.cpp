#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    int x; cin >> x;
    n -= x;
  }
  cout << n;
}
