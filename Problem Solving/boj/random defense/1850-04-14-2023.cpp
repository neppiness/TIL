#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

ll gcd(ll a, ll b) {
  if(a < b) swap(a, b);
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m; cin >> n >> m;
  ll x = max(n, m) - min(n, m);
  if(n == m) x = n;
  if(min(n, m) == 1) x = 1;
  s.resize(x);
  for(ll i = 0; i < x; i++)
    s[i] = '1';
  cout << s;
}