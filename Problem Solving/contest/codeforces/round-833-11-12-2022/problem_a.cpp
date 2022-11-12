#include <bits/stdc++.h>
using namespace std;

int n, t;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--) {
    cin >> n;
    cout << (n - 1)/2 + 1 << '\n';
  }
}