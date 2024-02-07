#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a = 1, b = 0;
  while (n--) {
    int tmp_a = 0;
    int tmp_b = 0;
    tmp_b += (a + b);
    tmp_a += b;
    swap(a, tmp_a);
    swap(b, tmp_b);
  }
  cout << a << ' ' << b;
}
