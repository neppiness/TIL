#include <bits/stdc++.h>
using namespace std;
using ll = long long; 

const int MX = 5'000'000;

ll minDiv[MX + 2];

void setup() {
  memset(minDiv, 0x7f, sizeof(minDiv));
  minDiv[1] = 1;

  for (ll i = 2; i <= MX; i++) {
    minDiv[i] = min(minDiv[i], i);
    for (ll j = i; j * i <= MX; j++)
      minDiv[j * i] = min(minDiv[j * i], i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();

  int n, x; cin >> n;
  while (n--) {
    cin >> x;
    while (x != 1) {
      cout << minDiv[x] << ' ';
      x /= minDiv[x];
    }
    cout << '\n';
  }
}