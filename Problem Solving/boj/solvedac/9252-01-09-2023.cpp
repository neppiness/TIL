#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;

string key, lck;
int len[MX + 2][MX + 2]; // len[keyidx][lckidx]
int idx[MX + 2][MX + 2]; // idx[keyidx][lckidx]

int solve(int keyidx, int lckidx) {
  if(keyidx == key.length()) return;
  int &tmplen = len[keyidx][lckidx];
  if(tmplen != -1) return tmplen;
  if(keyidx == 0)
    return tmplen = (key[keyidx] == lck[lckidx]);

  int &tmpidx = idx[keyidx][lckidx];
  tmpidx = idx[keyidx - 1][lckidx];

  int mx = -1;
  for(int lidx = 0; lidx < lckidx; lidx) {
    int t = solve(keyidx - 1, lidx);
    if(mx >= t) 
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> key >> lck;
  for(int i = 0; i < lck.length(); i++) {
    
  }
}