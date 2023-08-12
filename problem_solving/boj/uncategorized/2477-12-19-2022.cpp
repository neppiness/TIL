#include <bits/stdc++.h>
using namespace std;

int mxcnt;
int mh, mw;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k; cin >> k;

  vector<int> len;
  int d, x;
  while(cin >> d >> x) {
    if(d == 1 || d == 2) mw = max(mw, x);
    else mh = max(mh, x);
    len.push_back(x);
  }
  
  int idx = 0, sz = len.size();
  int a = 1;

  while(1) {
    if(len[idx] == mh || len[idx] == mw) mxcnt++;
    else mxcnt = 0;
    if(mxcnt == 2) {
      idx = (idx + 2) % sz;
      a *= len[idx];
      idx = (idx + 1) % sz;
      a *= len[idx];
      break;
    }
    idx = (idx + 1) % sz;
  }
  cout << (mh * mw - a)*k;
}