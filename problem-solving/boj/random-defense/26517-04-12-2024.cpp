#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll k;
  cin >> k;
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a * k + b == c * k + d) {
    cout << "Yes " << a * k + b;
  } else {
    cout << "No";
  }
}
