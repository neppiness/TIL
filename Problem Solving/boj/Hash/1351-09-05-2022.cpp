#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
int p, q;
unordered_map<ll, ll> um;

ll div(ll x) {
  if(x == 0) return 1;
  if(um[x]) return um[x];

  um[x] = div(x/p) + div(x/q);
  return um[x];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> p >> q;
  cout << div(n);
}