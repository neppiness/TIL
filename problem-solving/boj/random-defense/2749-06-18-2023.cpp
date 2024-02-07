#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int kMod = 1'000'000;

struct mat {
  ll a, b, c, d;
  mat(ll a_, ll b_, ll c_, ll d_): a(a_), b(b_), c(c_), d(d_) {}

  mat operator * (mat &rt) {
    return mat(
        (a * rt.a + b * rt.c) % kMod,
        (a * rt.b + b * rt.d) % kMod,
        (c * rt.a + d * rt.c) % kMod,
        (c * rt.b + d * rt.d) % kMod
    );
  }
} one(1, 1, 1, 0);

mat mmul(ll x) {
  if (x == 1) return one;
  mat half = mmul(x / 2);
  mat halfsquare = half * half;
  if (x % 2) return one * halfsquare;
  return halfsquare;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin >> n;
  cout << mmul(n).c;
}