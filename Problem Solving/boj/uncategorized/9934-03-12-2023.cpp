#include <bits/stdc++.h>
using namespace std;

int n, mx;
vector<int> a;
vector<int> el[12];

void tr(int st, int en, int lv) {
  if(st == en) { el[lv].push_back(a[st]); return; }
  int mid = (st + en)/2;
  el[lv].push_back(a[mid]);
  tr(st, mid - 1, lv + 1);
  tr(mid + 1, en, lv + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  mx = (1 << n) - 1;
  a.resize(mx);

  for(int i = 0; i < mx; i++)
    cin >> a[i];

  tr(0, mx - 1, 0);
  for(int lv = 0; lv < n; lv++) {
    for(int x : el[lv]) cout << x << ' ';
    cout << '\n';
  }
}