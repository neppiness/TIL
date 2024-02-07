#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;

int lcs[MX + 2][MX + 2]; // [keyidx][lckidx]
string key, lck;

void solve(int keyidx) { // keyidx + 1 배열을 채우는 함수
  if(keyidx == key.length()) return;

  int mx = 0;
  for(int lckidx = 0; lckidx < lck.length(); lckidx++) { // lckidx + 1 배열을 채우는 함수
    mx = max(mx, lcs[keyidx][lckidx]);
    bool matched = (key[keyidx] == lck[lckidx]);
    lcs[keyidx + 1][lckidx + 1] = max(mx + matched, lcs[keyidx][lckidx + 1]);
  }
  solve(keyidx + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> key >> lck;
  solve(0);

  cout << *max_element(lcs[key.length()], lcs[key.length()] + lck.length() + 1);
}