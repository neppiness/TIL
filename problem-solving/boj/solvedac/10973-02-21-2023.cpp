#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> perm(n);
  for(int i = 0; i < n; i++)
    cin >> perm[i];
  if(prev_permutation(perm.begin(), perm.end()))
    for(int p : perm) cout << p << ' ';
  else cout << -1;
}