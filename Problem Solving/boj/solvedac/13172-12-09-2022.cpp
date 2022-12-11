#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int PR = 1'000'000'007;

ll po(ll n, ll p) {
  if(p == 1) return n;
  ll n_po_half = po(n, p/2);
  if(p % 2 == 0) return (n_po_half * n_po_half) % PR;
  return ((n * n_po_half) % PR * n_po_half) % PR;
}

ll gcd(int a, int b) { return (a ? gcd(b%a, a) : b); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  ll sum = 0;
  while(t--) {
    ll n, s; cin >> n >> s;
    ll g = gcd(n, s);
    n /= g; s/= g;
    ll inv = po(n, PR - 2);
    sum += (s * inv) % PR;
    sum %= PR;
  }
  cout << sum;
}