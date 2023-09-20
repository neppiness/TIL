#include <bits/stdc++.h>
using namespace std;

const int MX = (1 << 20);

bool is_occupied[MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while (m--) {
    int mn = MX;
    int x; cin >> x;

    int tmp = x;
    while (tmp) {
      if (is_occupied[tmp]) mn = tmp;
      tmp /= 2;
    }
    if (mn == MX) {
      is_occupied[x] = 1;
      mn = 0;
    }
    cout << mn << '\n';
  }
}
