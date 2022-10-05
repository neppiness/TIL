#include <bits/stdc++.h>
using namespace std;

const int MX = 1002;

int n, k;
int nxt[MX];
int pre[MX];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 1; i < n + 1; i++) {
    nxt[i - 1] = i;
    pre[i + 1] = i;
  }
  nxt[n] = 1;
  pre[1] = n;

  int cnt = 0, cur = 0;
  cout << "<";
  while(cnt != n){
    for(int i = 0; i < k; i++) cur = nxt[cur];
    cnt++;
    if(cnt != n) cout << cur << ", ";
    else cout << cur << ">";
    nxt[pre[cur]] = nxt[cur];
    pre[nxt[cur]] = pre[cur];
  }
}