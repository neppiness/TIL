#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m; cin >> n >> m;
  ll x = gcd(n, m);
  while(x--) cout << 1;
}