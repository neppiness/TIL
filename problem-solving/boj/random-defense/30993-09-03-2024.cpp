#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fact(int n) {
  long long n_fact = 1;
  for (int i = 2; i <= n; i++)
    n_fact *= i;
  return n_fact;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, a, b, c;
  cin >> n >> a >> b >> c;
  cout << fact(n) / (fact(a) * fact(b) * fact(c));
}
