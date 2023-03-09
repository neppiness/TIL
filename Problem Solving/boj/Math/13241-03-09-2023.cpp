#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll a, b; cin >> a >> b;
  cout << lcm(a, b);
}