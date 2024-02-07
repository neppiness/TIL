#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int kMax = 1'000'000;

ll g[kMax + 2];
int minPrDiv[kMax + 2];

void setup() {
  for (int i = 2; i <= kMax; i++) {
    if (minPrDiv[i] != 0) continue;
    minPrDiv[i] = i;
    for (int j = i; (ll)i * j <= kMax; j++) {
      if (minPrDiv[(ll)i * j] != 0) continue;
      minPrDiv[(ll)i * j] = i;
    }
  }
  g[1] = 1;
  for (int i = 2; i <= kMax; i++) g[i] = i + g[i / minPrDiv[i]];

  
  for (int i = 2; i <= 10; i++)
    cout << g[i] << ' ';
  cout << '\n';



  for (int i = 2; i <= kMax; i++) g[i] += g[i - 1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();



  int t; cin >> t;
  while (t--) {
    int x; cin >> x;
    cout << g[x] << '\n';
  }
}