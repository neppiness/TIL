#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x;
  int tot = 0;
  while (cin >> x) {
    if (x < 40) x = 40;
    tot += x;
  }
  cout << tot / 5;
}
