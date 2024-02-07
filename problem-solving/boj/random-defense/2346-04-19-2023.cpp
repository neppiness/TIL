#include <bits/stdc++.h>
using namespace std;

// 1-indexed
int n;
vector<int> nxt, prv, val;

int move(int cur, int x, vector<int> &arr) {
  while(x--) cur = arr[cur];
  return cur;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  nxt.resize(n + 1);
  prv.resize(n + 1);
  val.resize(n + 1);

  for(int i = 1; i <= n; i++)
    cin >> val[i];

  for(int i = 1; i <= n; i++) {
    nxt[i] = i + 1;
    prv[i] = i - 1;
  }
  nxt[n] = 1, prv[1] = n;

  int cur = 1;
  while(n--) {
    cout << cur << ' ';
    prv[nxt[cur]] = prv[cur];
    nxt[prv[cur]] = nxt[cur];
    int mv = val[cur];
    if(mv < 0) cur = move(cur, -mv, prv);
    else cur = move(cur, mv, nxt);
  }
}