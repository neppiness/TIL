#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;
const int INF = 2'000;
int lcil[MX + 2]; // last character indexed by seq. length

string key, lck;

void solve(int keyidx) {
  if(keyidx == key.length()) return;
  for(int lckidx = 0; lckidx < lck.length(); lckidx++) {
    if(key[keyidx] != lck[lckidx]) continue;
    int *it = lower_bound(lcil, lcil + MX, lckidx);
    *it = lckidx;
  }
  solve(keyidx + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> key >> lck;
  fill(lcil + 1, lcil + MX + 2, INF); 
  solve(0);

  cout << lower_bound(lcil, lcil + MX, INF) - lcil - 1;
}