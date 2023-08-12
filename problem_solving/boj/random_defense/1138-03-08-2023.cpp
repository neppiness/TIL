#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> perm, chk;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  chk.resize(n);
  for(int i = 0; i < n; i++)
    cin >> chk[i];

  perm.resize(n);
  for(int i = 0; i < n; i++)
    perm[i] = (i + 1);

  do {
    bool is_found = 1;
    for(int i = 0; i < n; i++) {
      int chkidx = perm[i] - 1;
      int cnt = 0;
      for(int j = 0; j < i; j++)
        cnt += (perm[j] > perm[i]);
      if(cnt != chk[chkidx]) { is_found = 0; break; }
    }
    if(is_found) break;
  } while(next_permutation(perm.begin(), perm.end()));
  for(auto x : perm) cout << x << ' ';
}