#include <bits/stdc++.h>
using namespace std;

int n;
int no[2][4] = {{1, 3, 7, 9}, {2, 3, 5, 7}}; // no[is_oneth][idx]

void solve(int lv, int cur) {
  if(lv == 0) {
    cout << cur << '\n';
    return;
  }
  cur *= 10;
  bool is_oneth = (lv == n);
  for(int idx = 0; idx < 4; idx++) {
    int nxt = cur + no[is_oneth][idx];
    bool is_nxt_pr = 1;
    for(int i = 2; i * i <= nxt; i++)
      if(nxt % i == 0) {
        is_nxt_pr = 0;
        break;
      }
    if(!is_nxt_pr) continue;
    solve(lv - 1, nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  solve(n, 0);
}