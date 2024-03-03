#include <bits/stdc++.h>
using namespace std;

int a[1'000'001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a[x] = i;
  }

  int mx_len = 0;
  int len = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] < a[i]) {
      len++;
    } else {
      mx_len = max(mx_len, len);
      len = 1;
    }
  }
  mx_len = max(mx_len, len);
  cout << n - mx_len;
}
