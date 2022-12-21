#include <bits/stdc++.h>
using namespace std;

int col[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  int idx, h;
  int mnx = 0x7f7f7f7f, mxx = 0, mxh = 0;
  while(n--) {
    cin >> idx >> h;
    col[idx] = h;
    mxx = max(mxx, idx + 1);
    mnx = min(mnx, idx);
    mxh = max(mxh, h);
  }

  int totarea = (mxx - mnx) * mxh;

  int area1 = 0;
  h = 0;
  for(int i = mnx; i < mxx; i++) {
    h = max(h, col[i]);
    area1 += h;
  }
  area1 = totarea - area1;

  int area2 = 0;
  h = 0;
  for(int i = mxx; i >= mnx; i--) {
    h = max(h, col[i]);
    area2 += h;
  }
  area2 = totarea - area2;
  
  cout << totarea - area1 - area2;
}