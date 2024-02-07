#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1'000'000'007;

unordered_map<ll, ll> p1;
unordered_map<ll, ll> p2;


ll po(ll n, ll p) {
  if(p.find(n) != p.end()) return (p[n]) % M;
  if(n % 2 == 0) return (po(n/2) * po(n/2)) % M;
  else return po(1) * po(n/2) * po(n/2);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin >> n;

}
