#include <bits/stdc++.h>
using namespace std;

int n;

int solve() {
  for(int x = 1; x <= 1000000; x++) {
    int tmp = x, sum = x;
    for(int i = 0; i < 7; i++) {
      sum += tmp % 10;
      tmp /= 10;
    }
    if(sum == n) return x;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cout << solve();
}