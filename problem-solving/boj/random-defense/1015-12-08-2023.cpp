#include <bits/stdc++.h>
using namespace std;

int a[52], b[52];
bool is_used[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (is_used[j]) continue;
      if (a[i] == b[j]) {
        is_used[j] = 1;
        cout << j << ' ';
        break;
      }
    }
  }
}
