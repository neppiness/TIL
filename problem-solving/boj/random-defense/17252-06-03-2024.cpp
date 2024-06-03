#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  if (n == 0) {
    cout << "NO";
    return 0;
  }
  for (; n != 0; n /= 3) {
    int rest = n % 3;
    if (rest != 2) continue;
    cout << "NO";
    return 0;
  }
  cout << "YES";
}
