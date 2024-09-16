#include <bits/stdc++.h>
using namespace std;

int cnt;
int cow[12];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cow, -1, sizeof(cow));

  int n; cin >> n;
  while (n--) {
    int x, rl; cin >> x >> rl;
    if (cow[x] != -1) {
      cnt += (cow[x] != rl);
    }
    cow[x] = rl;
  }
  cout << cnt;
}
