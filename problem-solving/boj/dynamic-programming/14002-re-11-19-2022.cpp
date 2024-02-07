#include <bits/stdc++.h>
using namespace std;

const int MX = 1002;

stack<int> ans;
int b[MX];
int mxsz = 0, n;

void solve(int st, stack<int> stk) {
  stk.push(st);
  if(st + 1 == n) return;

  solve(st + 1, stk);

  for(int i = st + 1; i < n; i++) {
    if(b[stk.top()] > b[i]) {
      stk.pop();
      stk.push(i);
      solve(i + 1, stk);
    }
  }
  if(mxsz < stk.size()) {
    mxsz = stk.size();
    ans = stk;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> b[i];

  stack<int> stk;
  solve(0, stk);

  cout << ans.size() << '\n';
  while(!ans.empty()) {
    cout << b[ans.top()] << ' ';
    ans.pop();
  }
}