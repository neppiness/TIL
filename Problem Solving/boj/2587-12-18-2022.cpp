#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 5;
  vector<int> a;

  int sum = 0;
  while(n--) {
    int x; cin >> x;
    sum += x;
    a.push_back(x);
  }

  sort(a.begin(), a.end());

  cout << sum / 5 << '\n';
  cout << a[2];
}