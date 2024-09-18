#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int seq = 1;
  while (n != 0) {
    cout << seq << ". ";
    if (n % 2) {
      cout << "odd ";
    } else {
      cout << "even ";
    }
    n *= 3;
    n++;
    n /= 2;
    n *= 3;
    cout << n / 9 << '\n';

    cin >> n;
    seq++;
  }
}
