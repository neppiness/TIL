#include <bits/stdc++.h>
using namespace std;

const int MX = 100'002;

int n;
int in[MX], po[MX]; // 1-indexed
int inidx[MX];

void solve(int stin, int enin, int pidxpost) {
  int par = po[pidxpost];
  int paridxin = inidx[par];
  cout << par << ' ';
  int llen = paridxin - stin;
  int rlen = enin - paridxin;
  int lparidx = pidxpost - rlen - 1;
  int rparidx = pidxpost - 1;
  if(llen > 0) solve(stin, paridxin - 1, lparidx);
  if(rlen > 0) solve(paridxin + 1, enin, rparidx);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> in[i];
    inidx[in[i]] = i; // input: node no. return: index value
  }
  for(int i = 1; i <= n; i++)
    cin >> po[i];

  solve(1, n, n);
}