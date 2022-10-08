#include <bits/stdc++.h>
using namespace std;

const int MX = 100'002;

int n;
int in[MX], post[MX];
int lc[MX], rc[MX];
int r[MX];

int llen(int pidxin) {
  int len = 0;
  pidxin--;
  while(pidxin >= 0 && !r[in[pidxin]]) {
    pidxin--;
    len++;
  }
  return len;
}

int rlen(int pidxin) {
  int len = 0;
  pidxin++;
  while(pidxin < n && !r[in[pidxin]]) {
    pidxin++;
    len++;
  }
  return len;
}

void srch(int pidxpost, int lev) {
  int par = post[pidxpost];
  r[par] = lev;
  int pidxin = find(in, in + n, par) - in;
  int ll = llen(pidxin);
  int rl = rlen(pidxin);

  int rcidx = pidxpost - 1;
  int lcidx = rcidx - rl;

  if(ll) {
    lc[par] = post[lcidx];
    r[post[lcidx]] = lev + 1;
    srch(lcidx, lev + 1);
  }
  if(rl) {
    rc[par] = post[rcidx];
    r[post[rcidx]] = lev + 1;
    srch(rcidx, lev + 1);
  }
}

void preorder(int r) {
  cout << r << ' ';
  if(lc[r]) preorder(lc[r]);
  if(rc[r]) preorder(rc[r]);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> in[i];
  for(int i = 0; i < n; i++)
    cin >> post[i];

  srch(n-1, 1);
  int root = post[n-1];
  preorder(root);
}