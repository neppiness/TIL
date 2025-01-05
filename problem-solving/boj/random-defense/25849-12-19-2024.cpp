#include <bits/stdc++.h>
using namespace std;

const int DE[] = {1, 5, 10, 20, 50, 100};
tuple<int, int, int> a[6];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 6; i++) {
    int x; cin >> x;
    a[i] = {DE[i] * x, -x, DE[i]};
  }
  sort(a, a + 6);
  auto [x, y, z] = a[5];
  cout << z;
}
