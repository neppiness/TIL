#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 100'002;
const int PMX = 10'000;

vector<int> prs;
int cnt[PMX];
int ispr[MX];

void init() {
  fill(ispr + 2, ispr + MX, 1);
  for(ll i = 2; i < MX; i++) {
    if(!ispr[i]) continue;
    prs.push_back(i);
    ispr[i] = prs.size() - 1;
    for(ll j = i; j*i < MX; j++)
      ispr[i*j] = 0;
  }
}

void chk(int x, int code) {
  x = abs(x);
  int i = 0;
  while(x != 1) {
    if(ispr[x]) {
      int i = ispr[x];
      cnt[i] += code;
      return;
    }
    if(x % prs[i] == 0) {
      cnt[i] += code;
      x /= prs[i];
      continue;
    }
    i++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  init();
  int n; cin >> n;

  int x; cin >> x;
  chk(x, 1);

  while(--n) {
    char op; int x;
    cin >> op >> x;
    if(op == '*') chk(x, 1);
    else chk(x, -1);
  }

  for(int i = 0; i < prs.size(); i++) {
    if(cnt[i] >= 0) continue;
    cout << "toothpaste";
    return 0;
  }
  cout << "mint chocolate";
}