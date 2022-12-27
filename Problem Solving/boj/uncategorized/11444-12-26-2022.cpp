#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1'000'000'007;
vector<vector<ll>> m = {{2, 1}, {1, 1}};
vector<vector<ll>> a = {{1, 0}, {0, 1}};

vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
  vector<vector<ll>> tmp = {{0, 0}, {0, 0}};

  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      for(int k = 0; k < 2; k++) {
        tmp[i][j] += (a[i][k] * b[k][j]) % M;
        tmp[i][j] %= M;
      }
  return tmp;
}

vector<vector<ll>> mpow(ll n) {
  if(n == 0) return a;
  if(n == 1) return m;

  vector<vector<ll>> tmp = mpow(n / 2);
  if(n % 2 == 0) return mul(tmp, tmp);
  vector<vector<ll>> tmp2 = mul(m, tmp);
  return mul(tmp2, tmp);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin >> n;
  vector<vector<ll>> mp = mpow(n / 2);

  if(n % 2 == 1) cout << mp[0][0];
  else cout << mp[1][0];
}