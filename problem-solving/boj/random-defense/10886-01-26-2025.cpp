#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a;
  int c = 0, nc = 0;
  while (n--) {
    cin >> a;
    c += a;
    nc += !a;
  }
  if (c > nc) {
    cout << "Junhee is cute!";
  } else {
    cout << "Junhee is not cute!";
  }
}
