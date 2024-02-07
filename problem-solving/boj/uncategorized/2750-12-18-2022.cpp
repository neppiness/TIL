#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a;
  while(n--) {
    int x; cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  for(int x : a) cout << x << '\n';
}