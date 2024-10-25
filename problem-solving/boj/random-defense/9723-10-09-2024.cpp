#include <bits/stdc++.h>
using namespace std;

const string YN[] = {"NO", "YES"};

int a[3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    for (int i = 0; i < 3; i++)
      cin >> a[i];
    sort(a, a + 3);
    cout << "Case #" << t << ": " << YN[a[2] * a[2] == a[0] * a[0] + a[1] * a[1]] << '\n';
  }
}
