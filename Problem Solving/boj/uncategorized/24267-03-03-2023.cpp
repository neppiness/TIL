#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long n; cin >> n;
  n = (n * (n - 1) * (n - 2)) / 6;
  cout << n << '\n' << 3;
}