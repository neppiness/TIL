#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> perm;
  for(int i = 1; i <= n; i++)
    perm.push_back(i);
  
  do {
    for(int p : perm) cout << p << ' ';
    cout << '\n';
  } while(next_permutation(perm.begin(), perm.end()));
}