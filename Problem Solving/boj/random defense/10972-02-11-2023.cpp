#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  while(n--) {
    int x; cin >> x;
    a.push_back(x);
  }
  if(!next_permutation(a.begin(), a.end())) cout << -1;
  else for(auto x : a) cout << x << ' ';
}