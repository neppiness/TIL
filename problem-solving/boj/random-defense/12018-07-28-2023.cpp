#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (n--) {
    int no, lim; cin >> no >> lim;
    vector<int> miles;
    for (int i = 0; i < no; i++) {
      int x; cin >> x;
      miles.push_back(x);
    }
    sort(miles.rbegin(), miles.rend());
    if (lim > no) a.push_back(1);
    else a.push_back(miles[lim - 1]);
  }

  sort(a.begin(), a.end());
  int cnt = 0, tot = 0;
  for (int x : a) {
    if (tot + x > m) break;
    cnt++; tot += x;
  }
  cout << cnt;
}