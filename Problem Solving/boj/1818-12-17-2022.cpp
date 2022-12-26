#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MX = 200'002;

int lnil[200'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(lnil + 1, lnil + MX, INF);

  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    auto idx = lower_bound(lnil + 1, lnil + MX, x);
    if(*idx > x) *idx = x;
    else *(idx + 1) = x;
  }
  auto len = lower_bound(lnil + 1, lnil + MX, INF) - lnil - 1;
  cout << n - len;
}