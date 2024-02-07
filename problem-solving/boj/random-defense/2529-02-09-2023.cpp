#include <bits/stdc++.h>
using namespace std;

int perm[10];
int mnans[10], mxans[10];
char ieq[10];

long long tot;
long long mn = 0x7f7f7f7f7f7f, mx;

bool sat(int idx) {
  int l = perm[idx];
  int r = perm[idx + 1];
  if(ieq[idx] == '<') return l < r;
  return l > r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  for(int i = 0; i < n; i++)
    cin >> ieq[i];

  for(int i = 0; i < 10; i++)
    perm[i] = i;
  
  do {
    tot = 0; bool isvalid = 1;
    for(int i = 0; i < n; i++) {
      if(sat(i)) continue;
      isvalid = 0;
      break;
    }
    if(!isvalid) continue;
    for(int i = 0; i <= n; i++) {
      tot *= 10;
      tot += perm[i];
    }
    if(mn > tot) {
      mn = min(tot, mn);
      for(int i = 0; i <= n; i++)
        mnans[i] = perm[i];
    }
    if(mx < tot) {
      mx = max(tot, mx);
      for(int i = 0; i <= n; i++)
        mxans[i] = perm[i];
    }
  } while(next_permutation(perm, perm + 10));

  for(int i = 0; i <= n; i++)
    cout << mxans[i];
  cout << '\n';
  for(int i = 0; i <= n; i++)
    cout << mnans[i];
}