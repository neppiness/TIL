#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
vector<ll> ret;

void split_and_save() {
  int pos = 0;
  while (pos < s.size()) {
    int nxt = s.find(' ', pos);
    if (nxt == -1) nxt = s.size();
    ll a = stoll(s.substr(pos, nxt - pos));
    ret.push_back(a);
    pos = nxt + 1;
  }
}

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (getline(cin, s))
    split_and_save();

  ll ans = 1;
  for (int i = 0; i < ret.size(); i++) {
    for (int j = 0; j < i; j++) {
      ll x = ret[i], y = ret[j];
      ans = max(ans, gcd(x, y));
    }
  }
  cout << ans;
}
