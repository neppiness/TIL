#include <bits/stdc++.h>
using namespace std;

const string ANS[] = {"Bob", "Alice"};
int a[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    while ((n + 1) / 2 >= 2) {
      for (int i = 0; i < (n + 1) / 2; i++) {
        a[i] += a[n - i - 1];
      }
      n = (n + 1) / 2;
    }
    cout << "Case #" << c << ": " << ANS[a[0] > a[1]] << '\n';
  }
}
