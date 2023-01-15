#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 200;

int n, m, k, nm;
ll cache[MX + 2][MX + 2];

ll bi(int p, int q) {
  if(q == 0 || q == p) return 1;
  ll &ret = cache[p][q];
  if(ret != -1) return ret;
  return ret = bi(p - 1, q - 1) + bi(p - 1, q);
}

int setplace(int topick) {
  int idx = topick - 1;
  while(1) {
    if(k - bi(idx, topick - 1) <= 0) break;
    k -= bi(idx, topick - 1);
    idx++;
    if(idx == nm) return -1;
  }
  return idx;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n >> m >> k;

  nm = n + m;
  bool arr[nm] = {};

  int topick = m;
  while(topick) {
    int pl = setplace(topick);
    if(pl == -1) {
      cout << -1;
      return 0;
    }
    arr[pl] = 1;
    topick--;
  }

  for(int i = nm - 1; i >= 0; i--) {
    if(arr[i]) cout << 'z';
    else cout << 'a';
  }
}  