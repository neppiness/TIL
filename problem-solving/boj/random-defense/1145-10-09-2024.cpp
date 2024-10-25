#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a[5];
  for (int i = 0; i < 5; i++)
    cin >> a[i];

  for (int n = 1; n <= 100'000; n++) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
      if (n % a[i]) continue;
      cnt++;
    }
    if (cnt >= 3) {
       cout << n;
       return 0;
    }
  }
}
