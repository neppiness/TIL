#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ll mul, div = 1;
  cin >> mul;

  while(--n) {
    char op; ll x; 
    cin >> op >> x;
    if(op == '*') mul *= x;
    else div *= x;
  }
  mul = abs(mul); div = abs(div);
  ll g = gcd(mul, div);
  mul /= g; div /= g;

  if(div == 1) cout << "mint chocolate";
  else cout << "toothpaste";
}