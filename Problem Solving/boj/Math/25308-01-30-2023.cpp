#include <bits/stdc++.h>
using namespace std;

const double A_ERR = 0.0001;
const double SQ2O2 = sqrt(2)/(double)2;
const int MOD = 8;

int a[MOD], comb[MOD];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < MOD; i++) {
    cin >> a[i];
    comb[i] = i;
  }

  int cnt = 0;
  do {
    bool isvalid = 1;
    for(int i = 0; i < MOD; i++) {
      int i0 = comb[i];
      int i1 = comb[(i + 1) % MOD];
      int i2 = comb[(i + 2) % MOD];

      double oa[2] = {0, (double)a[i0]};
      double ob[2] = {(double)a[i1] * SQ2O2, (double)a[i1] * SQ2O2};
      double oc[2] = {(double)a[i2], 0};

      double ab[2] = {ob[0] - oa[0], ob[1] - oa[1]};
      double bc[2] = {oc[0] - ob[0], oc[1] - ob[1]};

      double res = ab[0] * bc[1] - ab[1] * bc[0];
      if(res > A_ERR) { isvalid = 0; break; }
    }
    if(isvalid) cnt++;
  } while(next_permutation(comb, comb + MOD));
  cout << cnt;
}