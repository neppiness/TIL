#include <bits/stdc++.h>
using namespace std;

int n = 4;
int a[] = {1, 1, 1, 1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int lbidx = lower_bound(a, a + n, 2) - a;
  int ubidx = upper_bound(a, a + n, 2) - a;
  cout << lbidx << '\n';
  cout << ubidx << '\n';
}