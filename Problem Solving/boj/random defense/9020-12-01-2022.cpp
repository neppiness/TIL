#include <bits/stdc++.h>
using namespace std;

int ispr[10'002];
vector<int> pr;

void solve() {
  int x; cin >> x;

  int a, b;
  for(int p : pr) {
    if(x - p < p) break;
    if(ispr[x - p])
      a = p, b = x - p;
  }
  cout << a << ' ' << b << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(ispr, ispr + 10'002, 1);
  ispr[0] = ispr[1] = 0;

  for(int i = 2; i <= 5000; i++) {
    if(!ispr[i]) continue;
    pr.push_back(i);
    for(int j = i; i*j <= 5000; j++)
      ispr[i*j] = 0;
  }

  cout << pr.size();
  return 0;

  int t; cin >> t;
  while(t--) solve();
}